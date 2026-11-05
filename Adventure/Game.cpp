#include "Game.h"

Game::Game()
{
	this->playing = true;
}

Game::~Game()
{
}

void Game::InitGame() //Start() en Unity
{
	std::cout << "Starting the Game" << std::endl;
	NewPlayer();
}

void Game::MainMenu()
{
	std::cout << "-------MAIN MENU-------" << std::endl;
	std::cout << " 0: Quit Game" << std::endl;
	std::cout << " 1: Player Stats" << std::endl;
	std::cout << " 2: Enemy Stats" << std::endl;
	std::cout << " 3: Travel" << std::endl;
	std::cout << " 4: Level Up" << std::endl;
	std::cout << " 5: Skill Up" << std::endl;
	std::cout << " 6: Save Player" << std::endl;
	std::cout << " 7: Load Player" << std::endl;


	std::cout << " Enter Choice" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 0:
		this->playing = false;
		break;
	case 1:
		PrintPlayerStats();
		break;
	case 2:
		NewEnemy();
		break;
	case 3:
		Travel();
		break;
	case 4:
		LevelUp();
		break;
	case 5:
		SkillUp();
		break;
	case 6:
		SavePlayer();
		break;
	case 7:
		LoadPlayer();
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::GameOver()
{
	while (!player.IsAlive() && this->playing)
	{
		std::system("cls");

		int choice = 0;

		std::cout << "-----GAME OVER-----" << std::endl;
		std::cout << "Choose your action" << std::endl;
		std::cout << "0: Quit Game" << std::endl;
		std::cout << "1: Restart from the beginning" << std::endl;
		std::cout << "2: Restart from last save file" << std::endl;

		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			choice = -1;
		}

		switch (choice)
		{
		case 0:
			std::system("cls");
			this->playing = false;
			break;
		case 1:
			std::system("cls");
			NewPlayer();
			break;
		case 2:
			std::system("cls");
			LoadPlayer();
			break;
		default:
			std::cout << "Invalid Option" << std::endl;
			break;
		}
	}
}

void Game::Travel()
{
	this->ev.GenerateEvent(player);

	if (this->ev.GetPuzzleCompleted())
	{
		std::cout << "You solved the puzzle. You win!" << std::endl;
	}
}

void Game::SavePlayer()
{
	std::string fileName = "savePlayer.txt";
	std::ofstream outFile(fileName);
	if (outFile.is_open())
	{
		outFile << player.SaveStats() << " ";
	}
	else
	{
		std::cout << "Can not save Game" << std::endl;
	}
	outFile.close();
	std::cout << "Game Saved" << std::endl;
}

void Game::LoadPlayer()
{
	std::string fileName = "savePlayer.txt";
	player.LoadStats(fileName);
}

void Game::NewPlayer()
{
	player.InitPlayer("Inigodzilla");
}

void Game::NewEnemy()
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 9;
	if (i >= 7)
	{
		std::string name = "arkilyan M";
		int level = (rand() % 10);
		int hp = (rand() % 2);
		int xp = (rand() % 5);
		int damage = (rand() % 6);
		int defence = (rand() % 20);
		enemy = new Enemy(name, level, hp, damage, defence, xp);
		enemy->PrintEnemyStats();
	}
	else if (i >= 4)
	{
		std::string name = "Zenomorf";
		int level = (rand() % 10);
		int hp = (rand() % 2);
		int xp = (rand() % 5);
		int damage = (rand() % 6);
		int defence = (rand() % 20);
		enemy = new Enemy(name, level, hp, damage, defence, xp);
		enemy->PrintEnemyStats();
	}
	if (i >= 1)
	{
		std::string name = "RALPH, the dog eater";
		int level = (rand() % 10);
		int hp = (rand() % 2);
		int xp = (rand() % 5);
		int damage = (rand() % 6);
		int defence = (rand() % 20);
		enemy = new Enemy(name, level, hp, damage, defence, xp);
		enemy->PrintEnemyStats();
	}


}

void Game::PrintPlayerStats()
{
	player.PrintPlayerStats();
}

bool Game::GetPlaying()
{
	return this->playing;
}


void Game::LevelUp()
{
	player.LevelUp();
}

void Game::SkillUp()
{
	while (player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints() << " Skill points to use" << std::endl;
		std::cout << "--------Stats--------" << std::endl;
		std::cout << "1: Strength" << std::endl;
		std::cout << "2: Agility" << std::endl;
		std::cout << "3: Dexterity" << std::endl;
		std::cout << "4: Intelligence" << std::endl;
		std::cout << "5: Luck" << std::endl;
		std::cin >> choice;
		player.AddStats(choice, 1);
	}
	if(player.GetSkillPoints() <= 0)
	{
		std::cout << "Not enough Skill points" << std::endl;
	}
}