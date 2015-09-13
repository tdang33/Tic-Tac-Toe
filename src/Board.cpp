//
//  Board.cpp
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/28/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#include <iostream>
#include "Board.h"
using namespace std;

//clear the current board, so we can start a new game
void Board::clear(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			board[i][j] = ' ';
		}
	}
	count = 0;
}

//constructor . Create a new empty board
Board::Board(){
	clear();
}

//print current board
void Board::print(){
	cout << " |1|2|3|"<<endl;
	cout <<" -------"<<endl;
	for (int i = 0; i < N; i++){
		cout <<i+1<<"|";
		for (int j = 0; j < N; j++){
			cout <<board[i][j] <<"|";
			
		}
		cout <<endl<< " -------"<<endl;		
	}
}

//check to see the position (x,y) is eligible or not (for both the player and computer)
bool Board::checkMove(int x, int y){
	if (x >= 0 && x <= N && y >= 0 && y <= N && board[x][y] == ' '){
		return true;
	}
	return false;
}

//put X or O at clear the cell at position (x,y)
void Board::setValue(int x, int y, char c){
	board[x][y] = c;
	if ( c == ' '){
		count--;
	}else {
		count++;
	}
	return;
}

//check if the game is over after the move at position (x,y) or not
bool Board::win(int x, int y){
	// check for columns
	int temp = 0;
	for (int i = 0; i < N ; i ++){
		if (board[i][y] == board[x][y]) temp++;
	}
	if (temp == N) return true;
	
	
	//check for rows
	temp = 0;
	for (int i = 0; i < N ; i ++){
		if (board[x][i] == board[x][y]) temp++;
	}
	if (temp == N) return true;
	
	//check for diagnol
	temp = 0;
	int i = 0, j = 0;
	while ( x+ i <= N-1 && y + j <= N-1 && board[x+i][y+j] == board[x][y]){
		temp++;
		i++;
		j++;
	}

	i = 1, j = 1;
	while ( x - i >= 0 && y - j >= 0 && board[x-i][y-j] == board[x][y]){
		temp++;
		i++;
		j++;

	}	

	if (temp == N) return true;
	
	//check for reverse diagnol
	temp = 0;
	i = 0, j = 0;
	while ( x+ i <= N-1 && y - j >= 0 && board[x+i][y-j] == board[x][y]){
		temp++;
		i++;
		j++;
	}
	i = 1, j = 1;
	while ( x - i >= 0 && y + j <= N-1 && board[x-i][y+j] == board[x][y]){
		temp++;
		i++;
		j++;
	}	

	if (temp == N) return true;
	return false;
	
}

//determine if the game's result is draw or not.
bool Board::draw(){
	if (count == N*N){
		return true;
	}
	return false;
}

//return value at position (i,j)
char Board::getValue(int i, int j){
	return board[i][j];
}

//return number of cells with placed X or O
int Board::getCount(){
	return count;
}


