//
//  Game.h
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/28/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#ifndef __Tic_Tac_Toe__Game__
#define __Tic_Tac_Toe__Game__

#include <stdio.h>
#include "Board.h"
#include <vector>

class Game{
	private:
	Board board;
	public:
	Game();
	void play();
	char getcurrentSymbol(int);
	void run();
};
#endif /* defined(__Tic_Tac_Toe__Game__) */
