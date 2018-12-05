/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, turnO)
{
	TicTacToeBoard obj;
	Piece val = obj.toggleTurn();
	ASSERT_EQ(val, O);
}

TEST(TicTacToeBoardTest, turnX)
{
	TicTacToeBoard obj;
	Piece val = obj.toggleTurn();
	val = obj.toggleTurn();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, getpieceBlank)
{
	TicTacToeBoard obj;
	Piece val = obj.getPiece(0,0);
	ASSERT_EQ(val, Blank);
}

TEST(TicTacToeBoardTest, getpieceOutofBounds1)
{
	TicTacToeBoard obj;
	Piece val = obj.getPiece(4,0);
	ASSERT_EQ(val, Invalid);
}

TEST(TicTacToeBoardTest, getpieceOutofBounds2)
{
	TicTacToeBoard obj;
	Piece val = obj.getPiece(3,3);
	ASSERT_EQ(val, Invalid);
}

TEST(TicTacToeBoardTest, placepieceX)
{
	TicTacToeBoard obj;
	Piece val = obj.placePiece(0,0);
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, placepieceO)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	Piece val = obj.placePiece(0,1);
	ASSERT_EQ(val, O);
}

TEST(TicTacToeBoardTest, placepieceNOTblank)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	Piece val = obj.placePiece(0,0);
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, placepieceOutofBounds)
{
	TicTacToeBoard obj;
	Piece val = obj.placePiece(3,3);
	ASSERT_EQ(val, Invalid);
}

TEST(TicTacToeBoardTest, placeandgetpiece1)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	Piece val = obj.getPiece(0,0);
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, placeandgetpiece2)
{
	TicTacToeBoard obj;
	obj.placePiece(2,0);
	Piece val = obj.getPiece(2,0);
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner1)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(0,1);
	obj.placePiece(2,2);
	obj.placePiece(0,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner2)
{
	TicTacToeBoard obj;
	obj.placePiece(2,0);
	obj.placePiece(1,1);
	obj.placePiece(2,1);
	obj.placePiece(0,2);
	obj.placePiece(2,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner3)
{
	TicTacToeBoard obj;
	obj.placePiece(1,0);
	obj.placePiece(0,1);
	obj.placePiece(1,1);
	obj.placePiece(0,2);
	obj.placePiece(1,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner4)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,1);
	obj.placePiece(1,0);
	obj.placePiece(0,2);
	obj.placePiece(2,0);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner5)
{
	TicTacToeBoard obj;
	obj.placePiece(0,1);
	obj.placePiece(1,0);
	obj.placePiece(1,1);
	obj.placePiece(0,0);
	obj.placePiece(2,1);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner6)
{
	TicTacToeBoard obj;
	obj.placePiece(0,2);
	obj.placePiece(1,1);
	obj.placePiece(1,2);
	obj.placePiece(0,0);
	obj.placePiece(2,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner7)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(1,0);
	obj.placePiece(1,1);
	obj.placePiece(0,2);
	obj.placePiece(2,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, winner8)
{
	TicTacToeBoard obj;
	obj.placePiece(2,0);
	obj.placePiece(1,0);
	obj.placePiece(1,1);
	obj.placePiece(2,2);
	obj.placePiece(0,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, X);
}

TEST(TicTacToeBoardTest, gameNOTover)
{
	TicTacToeBoard obj;
	Piece val = obj.getWinner();
	ASSERT_EQ(val, Invalid);
}

TEST(TicTacToeBoardTest, gameoverNOwinner)
{
	TicTacToeBoard obj;
	obj.placePiece(0,0);
	obj.placePiece(0,1);
	obj.placePiece(0,2);
	obj.placePiece(1,0);
	obj.placePiece(1,1);
	obj.placePiece(2,2);
	obj.placePiece(2,1);
	obj.placePiece(2,0);
	obj.placePiece(1,2);
	Piece val = obj.getWinner();
	ASSERT_EQ(val, Blank);
}