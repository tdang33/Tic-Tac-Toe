//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/28/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#include <iostream>
#include "Board.h"
#include "Game.h"
#include <vector> 

using namespace std;


int main() {
	cout << "Hello. Welcome to the Tic Tac Toe game! " <<endl;
	Game game;
	game.run();
	cout <<endl << "See you again!!!!!!!!!!"<<endl;
	//  X X O
	//	O O X
	//	X X O
	//
	/*Board board;
	board.clear();
	board.setValue(0,0,'X');
	board.setValue(0,1,'X');
	board.setValue(0,2,'O');
	board.setValue(1,0,'O');
	board.setValue(1,1,'O');
	board.setValue(1,2,'X');
	board.setValue(2,0,'X');
	board.setValue(2,1,'X');
	board.setValue(2,2,'O');
	cout << board.win(2,2);*/
    return 0;
}
