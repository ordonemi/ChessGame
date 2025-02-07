/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "test.h"
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
#include "board.h"
using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void* p)
{
    Board* board = (Board*)p;

    if (pUI->getPreviousPosition()!= -1 && pUI->getSelectPosition() != -1)
    {
		board->move(pUI->getPreviousPosition(), pUI->getSelectPosition());
		pUI->clearSelectPosition();
        board->clearMoves();
    }
    if (pUI->getSelectPosition() != -1)
    {
        board->clearMoves();
    }
    board->draw(*pUI);
}

/*******************************************************
 * PARSE
 * Determine the nature of the move based on the input.
 * This is the only function understanding Smith notation
 ******************************************************/
void parse(const string& textMove, int& positionFrom, int& positionTo)
{
   string::const_iterator it = textMove.cbegin();

   // get the source
   int col = *it - 'a';
   it++;
   int row = *it - '1';
   it++;
   positionFrom = row * 8 + col;

   // get the destination
   col = *it - 'a';
   it++;
   row = *it - '1';
   it++;
   positionTo = row * 8 + col;

   // capture and promotion information
   char capture = ' ';
   char piecePromotion = ' ';
   bool castleK = false;
   bool castleQ = false;
   bool enpassant = false;
   for (; it != textMove.end(); ++it)
   {
      switch (*it)
      {
      case 'p':   // capture a pawn
      case 'n':   // capture a knight
      case 'b':   // capture a bishop
      case 'r':   // capture a rook
      case 'q':   // capture a queen
      case 'k':   // !! you can't capture a king you silly!
         capture = tolower(*it);
         break;

      case 'c':  // short castling or king's castle
         castleK = true;
         break;
      case 'C':  // long castling or queen's castle
         castleQ = true;
         break;
      case 'E':  // En-passant
         enpassant = true;
         break;

      case 'N':  // Promote to knight
      case 'B':  // Promote to Bishop
      case 'R':  // Promote to Rook
      case 'Q':  // Promote to Queen
         piecePromotion = *it;
         break;

      }
   }

   // error checking
   if (positionFrom < 0 || positionFrom >= 64 ||
       positionTo   < 0 || positionTo   >= 64)
      positionFrom = positionTo = -1;
}


/********************************************************
 * READ FILE
 * Read a file where moves are encoded in Smith notation
 ******************************************************/
void readFile(const char* fileName, char* board)
{
    //open the file
   ifstream fin(fileName);
   if (fin.fail())
      return;

    //read the file, one move at a time
   string textMove;
   bool valid = true;
   while (valid && fin >> textMove)
   {
      int positionFrom;
      int positionTo;
      parse(textMove, positionFrom, positionTo);
      //valid = move(board, positionFrom, positionTo);
   }

    //close and done
   fin.close();
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   Interface ui("Chess");    

   Board b;
   void* p = &b;
   
#ifdef _WIN32
 //  int    argc;
 //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
 //  string filename = argv[1];
   /*
   if (__argc == 2)
      readFile(__argv[1], board);
      */
#else // !_WIN32
   if (argc == 2)
      readFile(argv[1], board);
#endif // !_WIN32

   // set everything into action

   testRunner();
   ui.run(callBack, p);  
   return 0;
}
