#include <iostream>
#include "GameObject.h"
#include "Game.h"

void Game::displayMenu() {
	std::cout << "________________________________" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|    Welcome to bomb field!    |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|           a - Play           |" << std::endl;
	std::cout << "|         b - Controls         |" << std::endl;
	std::cout << "|           c - Quit           |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|______________________________|" << std::endl;

	// call functionality of UI
	menuFunction();
}

void Game::menuFunction() {
	char input;
	std::cin >> input;

	//control user's input a, b, and c
	if (input == 'a') {
		// call function to let player chose dificulty
		difficulty();
	}
	if (input == 'b') {
		// show controls
		std::cout << "" << std::endl;
		std::cout << "- Move with 'wasd'" << std::endl;
		std::cout << "- Press 'c' at any time if you want to exit the game." << std::endl;
		std::cout << "- To win get to the other side of the field!" << std::endl;
		std::cout << "- Careful, there are bombs hidden in the field..." << std::endl;
		std::cout << "     if your health goes below zero, you lose." << std::endl;
		std::cout << "- The difficulty setting changes the amount of bombs & your health." << std::endl;
		std::cout << "- Good luck!" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;

		// return to main menu
		displayMenu();
	}
	else if (input == 'c') {
		// quit
		return;
	}
}

void Game::printGameBoard() {
	//populate array with normal tiles
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			gameBoard[i][j] = block.getSymbol();
		}
	}
	//Put player on the array
	gameBoard[player.getY()][player.getX()] = player.getSymbol();

	//print the game board
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			std::cout << gameBoard[i][j];
		}
		std::cout << std::endl;
	}
}

void Game::difficulty() {

	char input = ' ';

	//display difficulty screen to show options
	std::cout << "________________________________" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "| Select a difficulty:         |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|   1 -  Easy                  |" << std::endl;
	std::cout << "|   2 -  Medium                |" << std::endl;
	std::cout << "|   3 -  Impossible            |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|   c - return to main menu    |" << std::endl;
	std::cout << "|                              |" << std::endl;
	std::cout << "|______________________________|" << std::endl;
	std::cin >> input;
	std::cout << " " << std::endl;

	// change game variables based on dificulty
	if (input == '1') {
		//easy difficulty, 100 health and 20 bombs
		player.health = 100;
		numDeathBlock = 20;
	}
	if (input == '2') {
		//medium difficulty, 80 health and 30 bombs
		player.health = 80;
		numDeathBlock = 30;
	}
	if (input == '3') {
		//impossible difficulty, 50 health and 50 bombs
		player.health = 50;
		numDeathBlock = 50;
	}
	else if (input == 'c') {
		//return to main menu
		displayMenu();
	}

	//set player's starting location
	player.setLocation(0, 0);

	//call function to begin to play the game
	playGame();
}

void Game::playGame() {
	char input = ' ';
	int Xlocation = player.getX();
	int Ylocation = player.getY();

	//Create an empty death block array
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			deadBlockLocation[i][j] = ' ';
		}
	}
	// place death blocks at random in the array
	for (int i = 0; i <= numDeathBlock; i++) {
		deadBlockLocation[rand() % 10][rand() % 15] = 'b';
	}

	//take in constant input (play the game)
	while (input != 'c') {
		printGameBoard();

		//check if player won and end the game
		if (Xlocation == 14 && Ylocation == 9) {
			std::cout << "You won! Hp left: " << player.health << std::endl;
			std::cout << " " << std::endl;
			break;
		}

		// move player's location & check if they're in the board
		// display message in case they're not
		std::cout << "Your move: ";
		std::cin >> input;
		
		if (input == 'w') {
			Ylocation--;
			if (Ylocation < 0) {
				Ylocation = 0;
				std::cout << "You can't leave the board." << std::endl;
			}
		}
		if (input == 's') {
			Ylocation++;
			if (Ylocation > 9) {
				Ylocation = 9;
				std::cout << "You can't leave the board." << std::endl;
			}
		}
		if (input == 'a') {
			Xlocation--;
			if (Xlocation < 0) {
				Xlocation = 0;
				std::cout << "You can't leave the board." << std::endl;
			}
		}
		else if (input == 'd') {
			Xlocation++;
			if (Xlocation > 14) {
				Xlocation = 14;
				std::cout << "You can't leave the board." << std::endl;
			}
		}

		// update location after player moves
		player.setLocation(Xlocation, Ylocation);

		// check if player hit a death block
		// by comparing their current location to the deathblock array
		if (deadBlockLocation[player.getY()][player.getX()] != ' ') {
			// update health and display message
			player.health -= 10;
			std::cout << std::endl;
			std::cout << "You stepped on a bomb! HP left: " << player.health << std::endl;
			std::cout << std::endl;

			// replace bomb so user can't hit it twice
			deadBlockLocation[player.getY()][player.getX()] = ' ';
		}

		// check if player still has hp left
		if (player.health <= 0) {
			std::cout << "You died" << std::endl;;
			std::cout << " " << std::endl;
			break;
		}
	}

	//return to the first function so user can play again
	displayMenu();
}