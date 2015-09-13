//
//  Computer.h
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/29/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#ifndef __Tic_Tac_Toe__Computer__
#define __Tic_Tac_Toe__Computer__

#include <stdio.h>
#include <iostream>
#include <vector>
//#include "Player.h"
#include "Board.h"
#include <vector>
using namespace std;

class Computer{
	private:
	
	public:
	vector<int> nextMove(Board &) ;
	vector<int> nextMoveAlphaBeta(Board &) ;
	vector<int> nextMoveDepth(Board &);
	vector<int> nextMoveDepthAlphaBeta(Board &);
	int minimax(Board &, bool, int, int) ;
	vector<int> minimaxDepth(Board &, bool, int, int) ;
	int minimaxAlphaBeta(Board &, bool, int, int , int , int );
	vector<int> minimaxDepthAlphaBeta(Board &, bool, int, int , int , int );
};
#endif /* defined(__Tic_Tac_Toe__Computer__) */
