#include <iostream>
#include "GameObject.h"
#include "Game.h"

int main()
{
	srand((unsigned int)time(nullptr));
	UserPlayer player;
	GameObject blocks;
	Game Game(player, blocks);
	Game.displayMenu();
}