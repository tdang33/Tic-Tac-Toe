//
//  Computer.cpp
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/29/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#include "Computer.h"
#include <iostream>
#include "Board.h"
#include <vector>

using namespace std;

//find the next optimal move for the computer with depth
vector<int> Computer::nextMoveDepth(Board & board){
	vector<int> v = {0,0};
	int M = 2, x = -1, y = -1, depth = INT_MAX;
	for (int i = 0; i < N;i++){
		for (int j = 0; j < N; j++){
			if (board.getValue(i, j) == ' '){
				vector<int> temp = minimaxDepth (board, true, i, j);
				if (temp[0] < M || (temp[0] == M && temp[1] <depth)){
					M = temp[0];
					depth = temp[1];
					x = i;
					y = j;
				}
				
			}
		}
	}
	v[0] = x+1;
	v[1] = y+1;
	return v;
}

// This is the most efficient one    !!!!!!!
//find the next optimal move for the computer with depth, Alpha-Beta
vector<int> Computer::nextMoveDepthAlphaBeta(Board & board){
	vector<int> v = {0,0};
	int M = 2, x = -1, y = -1, depth = INT_MAX;
	for (int i = 0; i < N;i++){
		for (int j = 0; j < N; j++){
			if (board.getValue(i, j) == ' '){
				vector<int> temp = minimaxDepthAlphaBeta (board, true, -2, 2, i, j);
				if (temp[0] < M || (temp[0] == M && temp[1] <depth)){
					M = temp[0];
					depth = temp[1];
					x = i;
					y = j;
				}
				
			}
		}
	}
	v[0] = x+1;
	v[1] = y+1;
	return v;
}



//without depth
vector<int> Computer::nextMove(Board & board){
	vector<int> v = {0,0};
	int M = 2, x = -1, y = -1;
	for (int i = 0; i < N;i++){
		for (int j = 0; j < N; j++){
			if (board.getValue(i, j) == ' '){
				int temp = minimax (board, true, i, j);
				if (temp < M){
					M = temp;
					x = i;
					y = j;
				}
				
			}
		}
	}
	v[0] = x+1;
	v[1] = y+1;
	return v;
}




//find next move with the help of alpha-beta
vector<int> Computer::nextMoveAlphaBeta(Board & board){
	vector<int> v = {0,0};
	int M = 2, x = -1, y = -1;
	for (int i = 0; i < N;i++){
		for (int j = 0; j < N; j++){
			if (board.getValue(i, j) == ' '){
				int temp = minimaxAlphaBeta (board, true, -2, 2, i, j);
				if (temp < M){
					M = temp;
					x = i;
					y = j;
				}
				
			}
		}
	}
	v[0] = x+1;
	v[1] = y+1;
	return v;
}

//-------------------------------------------------------------


//minimax algorithm to help determine the next move for the computer, with depth
vector<int> Computer::minimaxDepth(Board & board, bool isMax, int x , int y){
	vector<int> v;
	char c = (isMax?board.getComputerSymbol():board.getPlayerSymbol()); //computer move
	board.setValue(x,y,c); 
	
	if (board.win(x,y)){
		board.setValue(x,y,' ');	
		if (isMax){
			v.push_back(-1);
			v.push_back(0);
			return v;
		}else {
			v.push_back(1);
			v.push_back(0);
			return v;
		}
	}else if (board.draw()){
		board.setValue(x,y,' ');	
		v.push_back(0);
		v.push_back(0);
		return v;
	}
	
	//save the X positions of available cells into firstCoord, Y positions of available cells into secondCoord
	vector<int> firstCoord;
	vector<int> secondCoord;
	for (int i = 0; i < N; i++){
		for (int j = 0; j<N; j++){
			if (board.getValue(i,j) == ' '){
				firstCoord.push_back(i);
				secondCoord.push_back(j);
			}
		}
	}
	
	int len = (int) firstCoord.size();
	if (isMax == true){ // try to maximize
		int M = -2;
		vector<int> temp;
		for (int i = 0; i < len; i++){
			temp = minimaxDepth(board,false, firstCoord[i], secondCoord[i]);
			if (M < temp[0]){
				M = temp[0];
			}
		}
		board.setValue(x,y,' ');
		v.push_back(M);
		v.push_back(temp[1]+1);
		return v;
	}else {//try to minimize
		vector<int> temp;
		int m = 2;
		for (int i = 0; i < len; i++){
			temp = minimaxDepth(board, true, firstCoord[i], secondCoord[i]);
			if (m > temp[0]){
				m = temp[0];
			}
		}
		board.setValue(x,y,' ');
		v.push_back(m);
		v.push_back(temp[1]+1);
		return v;
	}
}





//minimax algorithm to help determine the next move for the computer, without depth
int Computer::minimax(Board & board, bool isMax, int x , int y){
	vector<int> v;
	char c = (isMax?board.getComputerSymbol():board.getPlayerSymbol()); //computer move
	board.setValue(x,y,c); 
	
	if (board.win(x,y)){
		board.setValue(x,y,' ');	
		if (isMax){
			return -1;
		}else {
			return 1;
		}
	}else if (board.draw()){
		board.setValue(x,y,' ');	
		return 0;
	}
	
	//save the X positions of available cells into firstCoord, Y positions of available cells into secondCoord
	vector<int> firstCoord;
	vector<int> secondCoord;
	for (int i = 0; i < N; i++){
		for (int j = 0; j<N; j++){
			if (board.getValue(i,j) == ' '){
				firstCoord.push_back(i);
				secondCoord.push_back(j);
			}
		}
	}
	
	int len = (int) firstCoord.size();
	if (isMax == true){ // try to maximize
		int M = -2;
		int temp;
		for (int i = 0; i < len; i++){
			temp = minimax(board,false, firstCoord[i], secondCoord[i]);
			if (M < temp){
				M = temp;
			}
		}
		board.setValue(x,y,' ');
		return M;
	}else {//try to minimize
		int temp;
		int m = 2;
		for (int i = 0; i < len; i++){
			temp = minimax(board, true, firstCoord[i], secondCoord[i]);
			if (m > temp){
				m = temp;
			}
		}
		board.setValue(x,y,' ');
		return m;
	}
}






//minimaxAlphaBeta algorithm with alpha-beta to help determine the next move for the computer
int Computer::minimaxAlphaBeta(Board & board, bool isMax, int alpha, int beta, int x , int y){
	char c = (isMax?board.getComputerSymbol():board.getPlayerSymbol()); //computer move
	board.setValue(x,y,c); 
	
	if (board.win(x,y)){
		board.setValue(x,y,' ');	
		if (isMax){
			return -1;
		}else {
			return 1;
		}
	}else if (board.draw()){
		board.setValue(x,y,' ');	
		return 0;
	}
	
	//save the X positions of available cells into firstCoord, Y positions of available cells into secondCoord
	vector<int> firstCoord;
	vector<int> secondCoord;
	for (int i = 0; i < N; i++){
		for (int j = 0; j<N; j++){
			if (board.getValue(i,j) == ' '){
				firstCoord.push_back(i);
				secondCoord.push_back(j);
			}
		}
	}
	
	int len = (int) firstCoord.size();
	if (isMax == true){ // try to maximize
		int M = -2;
		for (int i = 0; i < len; i++){
			int temp = minimaxAlphaBeta(board,false, alpha, beta, firstCoord[i], secondCoord[i]);
			if (M < temp){
				M = temp;
			}
			if (M > alpha){
				alpha = M;
			}	
			if (alpha >= beta){
				break;
			}
		}
		board.setValue(x,y,' ');
		return M;
	}else {//try to minimize
		int m = 2;
		for (int i = 0; i < len; i++){
			int temp = minimaxAlphaBeta(board, true, alpha, beta, firstCoord[i], secondCoord[i]);
			if (m > temp){
				m = temp;
			}
			if (m < beta){
				beta = m;
			}
			if (alpha >= beta){
				break;
			}
		}
		board.setValue(x,y,' ');
		return m;
	}
}





//minimax algorithm to help determine the next move for the computer, with depth, alpha - beta
vector<int> Computer::minimaxDepthAlphaBeta(Board & board, bool isMax, int alpha, int beta, int x , int y){
	vector<int> v;
	char c = (isMax?board.getComputerSymbol():board.getPlayerSymbol()); //computer move
	board.setValue(x,y,c); 
	
	if (board.win(x,y)){
		board.setValue(x,y,' ');	
		if (isMax){
			v.push_back(-1);
			v.push_back(0);
			return v;
		}else {
			v.push_back(1);
			v.push_back(0);
			return v;
		}
	}else if (board.draw()){
		board.setValue(x,y,' ');	
		v.push_back(0);
		v.push_back(0);
		return v;
	}
	
	//save the X positions of available cells into firstCoord, Y positions of available cells into secondCoord
	vector<int> firstCoord;
	vector<int> secondCoord;
	for (int i = 0; i < N; i++){
		for (int j = 0; j<N; j++){
			if (board.getValue(i,j) == ' '){
				firstCoord.push_back(i);
				secondCoord.push_back(j);
			}
		}
	}
	
	int len = (int) firstCoord.size();
	if (isMax == true){ // try to maximize
		int M = -2;
		vector<int> temp;
		for (int i = 0; i < len; i++){
			temp = minimaxDepthAlphaBeta(board,false, alpha, beta, firstCoord[i], secondCoord[i]);
			if (M < temp[0]){
				M = temp[0];
			}
			if (M > alpha){
				alpha = M;
			}
			if (alpha >= beta){
				break;
			}
		}
		board.setValue(x,y,' ');
		v.push_back(M);
		v.push_back(temp[1]+1);
		return v;
	}else {//try to minimize
		vector<int> temp;
		int m = 2;
		for (int i = 0; i < len; i++){
			temp = minimaxDepthAlphaBeta(board, true, alpha, beta , firstCoord[i], secondCoord[i]);
			if (m > temp[0]){
				m = temp[0];
			}
			if (m < beta){
				beta = m;
			}
			if (alpha >= beta){
				break;
			}
		}
		board.setValue(x,y,' ');
		v.push_back(m);
		v.push_back(temp[1]+1);
		return v;
	}
}

