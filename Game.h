#pragma once
#include "GameObject.h"

class Game {
private:
	char gameBoard[10][15];
	char deadBlockLocation[10][15];
	UserPlayer player;
	GameObject block;

public:
	int numDeathBlock;
	// constructor
	Game(UserPlayer p_, GameObject b_) {
		// Assign objects
		player = p_;
		block = b_;

		//Assign Symbols
		player.setSymbol('X');
		block.setSymbol('_');
	}

	/// <summary>
	/// display the game menu
	/// </summary>
	void displayMenu();

	/// <summary>
	/// call functionality for the main menu
	/// </summary>
	void menuFunction();

	/// <summary>
	/// print the game board for player to see
	/// </summary>
	void printGameBoard();

	/// <summary>
	/// change the dificulty setting
	/// </summary>
	void difficulty();

	/// <summary>
	/// manage the actual gameplay
	/// </summary>
	void playGame();
};
