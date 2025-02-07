/***********************************************************************
 * Source File:
 *    BOARD : Handles the chess board.
 * Author:
 *    Emilio Ordonez and Austin Jesperson
 * Summary:
 *    The chess board.
 ************************************************************************/

#include "board.h"

 /***************************************************
  * BOARD : DEFAULT CONSTRUCTOR
  ***************************************************/
Board::Board()
{
    clear();
    reset();
}

/***************************************************
 * CLEAR : FILL THE BOARD OUT WITH SPACES
 ***************************************************/
void Board::clear()
{
    for (int i = 0; i < 64; i++)
    {
        assign(Position(i),new Space(Position(i)));
    }
}


/***************************************************
 * ASSIGN : ASSIGN A PIECE A POSITION ON THE BOARD
 ***************************************************/
void Board::assign(Position pos, Piece* p)
{
    board[pos.getLocation()] = p;
}


/***************************************************
 * RESET : SET UP THE PIECES ON THE BOARD
 ***************************************************/
void Board::reset()
{
    //Place pieces on the board
    //White pieces;
	assign(Position(0), new Rook(Position(0), false));
	assign(Position(1), new Knight(Position(1), false));
	assign(Position(2), new Bishop(Position(2), false));
	assign(Position(4), new King(Position(4), false));
	assign(Position(3), new Queen(Position(3), false));
	assign(Position(5), new Bishop(Position(5), false));
    assign(Position(6), new Knight(Position(6), false));
    assign(Position(7), new Rook(Position(7), false));
    
	for (int i = 8; i < 16; i++)
	{
        assign(Position(i), new Pawn(Position(i), false));
	}

    //Black pieces;
	assign(Position(63), new Rook(Position(63), true));
	assign(Position(62), new Knight(Position(62), true));
	assign(Position(61), new Bishop(Position(61), true));
	assign(Position(60), new King(Position(60), true));
	assign(Position(59), new Queen(Position(59), true));
	assign(Position(58), new Bishop(Position(58), true));
    assign(Position(57), new Knight(Position(57), true));
    assign(Position(56), new Rook(Position(56), true));

   for (int i = 48; i < 56; i++)
    {
       assign(Position(i), new Pawn(Position(i), true));
    }
}
 
/*****************************************************
 * DRAW : DRAW THE BOARD, PIECES, AND POSSIBLE MOVES
 *****************************************************/
void Board::draw(const Interface& ui)
{
    gout.drawBoard();
	gout.drawHover(ui.getHoverPosition());
    gout.drawSelected(ui.getSelectPosition());

    if (ui.getSelectPosition() != -1)
    {
        Piece* selectedP = board[ui.getSelectPosition()];

        if (selectedP->isValid() && selectedP->isBlack() == blackTurn())
        {
            convertDirectionToMove(selectedP->getDirections(),selectedP->getLengthOfDirections(),selectedP);
            set <Move> ::iterator it;
            for (it = moves.begin(); it != moves.end(); ++it)
            {
                int loc = (*it).getDes().getLocation();
                gout.drawPossible(loc);
            }
        }
    }

    for(int i = 0; i < 64; i++)
    {
        board[i]->draw(gout);
    }
}

/***************************************************
 * MOVE : PERFORM A MOVE 
 ***************************************************/
bool Board::move(int positionFrom, int positionTo)
{
    // if valid move
    set <Move> ::iterator it;
    for (it = moves.begin(); it != moves.end(); ++it)
    {
        if (it->getDes() == Position(positionTo))
        {
            assign(Position(positionTo), board[positionFrom]); 
            board[positionTo]->assignPos(positionTo); 
            assign(Position(positionFrom), new Space(Position(positionFrom))); 
            currentMove++; 
            last = *it;

            //check for special moves
            if (it->getCastleQ())
            {
                if (board[positionTo]->isBlack())
                {
                    assign(Position(58), board[56]);
                    board[58]->assignPos(58);
                    assign(Position(56), new Space(Position(56))); 
                }
                else
                {
                    assign(Position(2), board[0]);
                    board[2]->assignPos(2);
                    assign(Position(0), new Space(Position(0)));
                }
            }
            if (it->getCastleK())
            {
                if (board[positionTo]->isBlack())
                {
                    assign(Position(61), board[63]); 
                    board[61]->assignPos(61);
                    assign(Position(63), new Space(Position(63)));
                }
                else
                {
                    assign(Position(5), board[7]);
                    board[5]->assignPos(5);
                    assign(Position(7), new Space(Position(7)));
                }
            }
            if (it->getEnPassant())
            {
                if (board[positionTo]->isBlack())
                {
                    assign(Position(it->getDes().getRow() + 1, it->getDes().getCol()), new Space(Position(it->getDes().getRow() + 1, it->getDes().getCol()))); 
                }
                else
                {
                    assign(Position(it->getDes().getRow() - 1, it->getDes().getCol()), new Space(Position(it->getDes().getRow() - 1, it->getDes().getCol())));
                }
            }

            if (board[positionTo]->getType() == PAWN)
            {
                if (board[positionTo]->getPosition().getRow() == 0)
                {
                    assign(Position(positionTo), new Queen(Position(positionTo), true));
                    board[positionTo]->assignPos(positionTo);
                }
                if (board[positionTo]->getPosition().getRow() == 7)
                {
                    assign(Position(positionTo), new Queen(Position(positionTo), false));
                    board[positionTo]->assignPos(positionTo);
                }
            }
            return true;
        }
    }
    return false;  
}

/***************************************************
 * BLACK TURN() : DETERMINE WHICH SIDE'S TURN IT IS
 ***************************************************/
bool Board::blackTurn()
{
    if (currentMove % 2 == 0)
    {
        return true;
    }
    return false;
}

/**************************************************************************
 * CONVERT DIRECTION TO MOVE() : GET POSSIBLE MOVES FROM PIECE'S DIRECTION
 **************************************************************************/
void Board::convertDirectionToMove(RC* movesArrayP, int length, Piece* currPiece)
{
	int c = currPiece->getPosition().getCol(); //current column
	int r = currPiece->getPosition().getRow(); //current row 
	int cc = c;
	int rr = r;
	Move m;

	// bishops, rooks, queens
	if (currPiece->ifSlide())
	{
		for (int i = 0; i < length; i++)
		{
			rr += movesArrayP[i].row;
			cc += movesArrayP[i].col;
			if ((rr * 8 + cc) >= 0 && (rr * 8 + cc) < 64)
			{
				while (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[rr * 8 + cc]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);
					rr += movesArrayP[i].row;
					cc += movesArrayP[i].col;
				}
				if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && currPiece->isBlack() != board[rr * 8 + cc]->isBlack())
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					m.setCapture(board[rr * 8 + cc]->getType());
					moves.insert(m);
				}

			}
			rr = r;
			cc = c;
		}
	}

	// pawn
	else if (currPiece->getType() == PAWN)
	{
		if (currPiece->isBlack()) // black pawn
		{
			rr = r - 2;  //row is r
			if (currPiece->getNMoves() == 0)
			{
				if (r == 6 && board[rr * 8 + cc]->getType() == SPACE && board[(r - 1) * 8 + cc]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);    // forward two blank spaces
				};
			};

			rr = r - 1;
			if (rr >= 0 && board[rr * 8 + cc]->getType() == SPACE)
			{
				m.setSrc(currPiece->getPosition());
				m.setDes(board[rr * 8 + cc]->getPosition());
				moves.insert(m);
				// forward one blank space
			}

			cc = c - 1;
			if (rr >= 0 && cc >= 0 && cc < 8 && !board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
			{
				m.setSrc(currPiece->getPosition());
				m.setDes(board[rr * 8 + cc]->getPosition());
				moves.insert(m);    // attack left
			}

			cc = c + 1;
			if (rr >= 0 && cc >= 0 && cc < 8 && !board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
			{
				m.setSrc(currPiece->getPosition());
				m.setDes(board[rr * 8 + cc]->getPosition());
				moves.insert(m);  // attack right
			}

			// what about en-passant and pawn promotion
			if (r == 3)
			{
				cc = c - 1;
				rr = r - 1;
				if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[r * 8 + cc]->getType() == PAWN && !board[r * 8 + cc]->isBlack() && Position(r * 8 + cc) == last.getDes())
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					m.setEnPassant();
					moves.insert(m);  // attack leftt

				};

				cc = c + 1;
				if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[r * 8 + cc]->getType() == PAWN && !board[r * 8 + cc]->isBlack() && Position(r * 8 + cc) == last.getDes())
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					m.setEnPassant();
					moves.insert(m);
				};  // attack right)

			};

		}

		else if (!currPiece->isBlack()) //white pawn
		{
			rr = r + 2; //row is r
			if (currPiece->getNMoves() == 0)
			{
				if (r == 1 && board[rr * 8 + cc]->getType() == SPACE && board[(r + 1) * 8 + cc]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);  // forward two blank spaces
				};
			};

			rr = r + 1;
			if (rr <= 7 && board[rr * 8 + cc]->getType() == SPACE)
			{
				m.setSrc(currPiece->getPosition());
				m.setDes(board[rr * 8 + cc]->getPosition());
				moves.insert(m);   //forward one blank space
			}

			cc = c - 1;
			if (rr < 8 && cc >= 0 && cc < 8 && board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
			{
				m.setSrc(currPiece->getPosition());
				m.setDes(board[rr * 8 + cc]->getPosition());
				moves.insert(m);    // attack left
			}

			cc = c + 1;
			if (rr < 8 && cc >= 0 && cc < 8 && board[rr * 8 + cc]->isBlack() && board[rr * 8 + cc]->getType() != SPACE)
			{
				m.setSrc(currPiece->getPosition());
				m.setDes(board[rr * 8 + cc]->getPosition());
				moves.insert(m);    // attack right
			}


			//what about en-passant and pawn promotion
			if (r == 4)
			{
				cc = c - 1;
				rr = r + 1;
				if (cc >= 0 && cc < 8 && board[r * 8 + cc]->getType() == PAWN && board[r * 8 + cc]->isBlack() && Position(r * 8 + cc) == last.getDes())
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					m.setEnPassant();
					moves.insert(m); // attack left
				};

				cc = c + 1;
				if (cc >= 0 && cc < 8 && board[r * 8 + cc]->getType() == PAWN && board[r * 8 + cc]->isBlack() && Position(r * 8 + cc) == last.getDes())
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					m.setEnPassant();
					moves.insert(m);  // attack right)
				};
			};

		}
	}

	// knight and king
	else if (currPiece->getType() == KNIGHT || currPiece->getType() == KING)
	{
		for (int i = 0; i < length; i++)
		{
			rr += movesArrayP[i].row;
			cc += movesArrayP[i].col;
			if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8)
			{
				if (board[rr * 8 + cc]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[rr * 8 + cc]->getPosition());
					moves.insert(m);
				}
				else
				{
					if (currPiece->isBlack() != board[rr * 8 + cc]->isBlack())
					{
						m.setSrc(currPiece->getPosition());
						m.setDes(board[rr * 8 + cc]->getPosition());
						moves.insert(m);
					}
				}

			}
			rr = r;
			cc = c;
		}
	}


	// castling
	if (currPiece->getType() == KING)
	{
		if (!currPiece->isBlack())
		{
			// white side, queen side
			if (currPiece->getNMoves() == 0 && board[0]->getType() == ROOK && board[0]->getNMoves() == 0)
			{
				// check to make sure spots in between are open
				if (board[1]->getType() == SPACE && board[2]->getType() == SPACE && board[3]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[1]->getPosition());
					m.setCastle(false);
					moves.insert(m);
				}
			}
			// white side, king side
			if (currPiece->getNMoves() == 0 && board[7]->getType() == ROOK && board[7]->getNMoves() == 0)
			{
				// check to make sure spots in between are open
				if (board[5]->getType() == SPACE && board[6]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[6]->getPosition());
					m.setCastle(true);
					moves.insert(m);
				}
			}
		}
		else
		{
			// black side, queen side
			if (currPiece->getNMoves() == 0 && board[0]->getType() == ROOK && board[0]->getNMoves() == 0)
			{
				// check to make sure spots in between are open
				if (board[57]->getType() == SPACE && board[58]->getType() == SPACE && board[59]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[57]->getPosition());
					m.setCastle(false);
					moves.insert(m);
				}
			}
			// white side, king side
			if (currPiece->getNMoves() == 0 && board[7]->getType() == ROOK && board[7]->getNMoves() == 0)
			{
				// check to make sure spots in between are open
				if (board[61]->getType() == SPACE && board[62]->getType() == SPACE)
				{
					m.setSrc(currPiece->getPosition());
					m.setDes(board[62]->getPosition());
					m.setCastle(true);
					moves.insert(m);
				}
			}
		}
	}

}