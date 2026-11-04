
#include "Game.h"

int main()
{
	Game game;
	game.InitGame();

	while (game.GetPlaying())
	{
		game.MainMenu();
	}

	return 0;
}
