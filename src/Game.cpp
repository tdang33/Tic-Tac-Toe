//
//  Game.cpp
//  Tic Tac Toe
//
//  Created by Thanh Dang on 8/28/15.
//  Copyright (c) 2015 ga. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Computer.h"
#include <vector>

using namespace std;

//create new game. A game can include many rounds if the player wants to play again
Game::Game(){
	board.clear();
}

//play the game. Here is the structure of how the game is played
void Game::play(){
	board.clear();
	Computer computer;
	bool flag = true;
	int current = 1;
	int x = -1, y = -1;
	vector<int> v; 
	int playerChoice;
	
	cout << "Please choose 'X' or 'O' to play.\nEnter 1 to choose 'X', 2 to choose 'O': "<<endl;
	cin >> playerChoice;
	while (playerChoice != 1 && playerChoice != 2){
		cout << "Incorrect choice! Enter your choice again. "<<endl;
		cout << "Enter 1 to choose 'X', 2 to choose 'O': "<<endl;
		cin >>playerChoice;
		if (playerChoice == 1 || playerChoice == 2) break;
	}
	
	if (playerChoice == 1){
		board.setPlayerSymbol('X');
		board.setComputerSymbol('O');
	}else {
		board.setPlayerSymbol('O');
		board.setComputerSymbol('X');	}
	//option for player to go first
	cout << "You play as " << board.getPlayerSymbol() <<". Let's start!"<<endl;
	cout << "Do you want to go first? y/n"<<endl;
	char playerGoFirst;
	cin >> playerGoFirst;
	
	if (playerGoFirst == 'Y' || playerGoFirst == 'y'){
		current = 1;
		cout << "OK. You go first!"<<endl;
	} else {
		cout << "OK. I go first!"<<endl;
		current = 2;
	}
		
		
	while (flag){
		board.print();
		cout <<endl;
		if (current == 1){ //get player move
		cout <<"Your turn. (" << board.getPlayerSymbol()<<" )"<<endl;
		cout << "Enter X coordinate of your move: ";
		cin >> x;
		cout << "Enter Y coordinate of your move: ";
		cin >> y;
		} else { // get computer move
		
			v = computer.nextMoveDepthAlphaBeta(board);
			x = v[0];
			y = v[1];
			
		}
		
		//check if the move is legit or not
		if (!board.checkMove(x-1, y-1)){
			cout <<endl<< "Not a legal move. Try again!"<<endl;
			continue; //if not, continue the loop
		}else {//if the move is legit, update the board
			
			board.setValue(x-1, y-1, getcurrentSymbol(current));
			
		}
		
		//check if the game is over or not
		if (board.win(x-1, y-1)){
			board.print();
			if (current == 1) {
				cout << "CONGRATULATIONS! YOU WON!"<<endl;
			}else {
				cout << "I WON!!!"<<endl;
			}
			break;
		}else if (board.draw()){
			board.print();
			cout << "Draw game!"<<endl;
			break;
		}else{ // if the game is not over, change current player between the player and the computer
			current = 3 - current;
		}
	}
}

//get symbol of the current player
char Game::getcurrentSymbol(int current){
	if (current == 1){
		return board.getPlayerSymbol();
	}else{
		return board.getComputerSymbol();
	}
}



//start the game
void Game::run(){
	bool flag = true;
	char x;
	while (flag){
		play();
		cout << "Do you want to play another game? y/n"<<endl;
		cin >> x;
		if (x == 'N' || x == 'n'){
			flag = false;
		}else{
			cout << "------------------------------------------------------"<<endl;
		}
	}

}