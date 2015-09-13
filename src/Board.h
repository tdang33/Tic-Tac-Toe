//
//  Board.h
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/28/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#ifndef __Tic_Tac_Toe__Board__
#define __Tic_Tac_Toe__Board__


#include <stdio.h>
using namespace std;


const int N = 3;
//const int M = 3;


class Board{
	private:
	char board[N][N];
	char playerSymbol;
	char computerSymbol;
	int count;
	public:
	Board();
	void clear();
	void print();
	bool checkMove(int, int);
	bool win(int, int);
	bool draw();
	char getValue(int, int);
	void setValue(int, int,char);
	int getCount();
	char getPlayerSymbol(){
		return playerSymbol;
	}
	char getComputerSymbol(){
		return computerSymbol;
	}
	void setPlayerSymbol(char c){
		playerSymbol = c;
	}
	void setComputerSymbol(char c){
		computerSymbol = c;
	}
};

#endif /* defined(__Tic_Tac_Toe__Board__) */
