/***********************************************************************
 * Header File:
 *    TEST PAWN : test the Pawn class
 * Author:
 *    Austin Jesperson
 ************************************************************************/

#pragma once

 /***************************************************
  * PAWN TEST
  * Test the Pawn class
  ***************************************************/

class PawnTest
{
public:
    void run() const
    {
        // Constructor
        constructor_default();

        // Assign
        pawn_blocked();
        pawn_regMove();
        pawn_firstMove();
        pawn_blockedFirstMove();
        pawn_blockedFirstMoveDouble();
        pawn_capture();
        pawn_noTeamCapture();
        pawn_enpassant();
        pawn_promote();
        pawn_promoteCapture();

    }
private:

    void constructor_default() const;

    void pawn_blocked() const;
    void pawn_regMove() const;
    void pawn_firstMove() const;
    void pawn_blockedFirstMove() const;
    void pawn_blockedFirstMoveDouble() const;
    void pawn_capture() const;
    void pawn_noTeamCapture() const;
    void pawn_enpassant() const;
    void pawn_promote() const;
    void pawn_promoteCapture() const;
};