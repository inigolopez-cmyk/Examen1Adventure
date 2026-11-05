#include "Game.h"

Game::Game()
{
	this->choice = 0;
	this->playing = true;
	this->enemy = nullptr;
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
	std::cout << " 8: Code" << std::endl;


	std::cout << " Enter Choice" << std::endl;
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
		this->playing = false;
		break;
	case 1:
		PrintPlayerStats();
		break;
	case 2:
		NewEnemy();
		break;
	case 3:
		std::system("cls");
		Travel();
		break;
	case 4:
		std::system("cls");
		LevelUp();
		break;
	case 5:		
		std::system("cls");
		SkillUp();
		break;
	case 6:
		std::system("cls");
		SavePlayer();
		break;
	case 7:
		std::system("cls");
		LoadPlayer();
		break;
	case 8:
		std::system("cls");
		CheatCode();
		break;
	default:
		std::cout << "Invalid Option" << std::endl;
		break;
	}
}

void Game::GameOver()
{
	//El while hace que no se deba de poner la funcion después de que muera el player. Con que !IsAlive, para el programa
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

		//Esto se añade siempre para que al poner otro tipo de respuestas que no sean int, no se muera el programa
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

	GameOver();

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
	//Se cambió la sintaxis para que sea más cómodo de ver la creación de enemigos

	if (enemy != nullptr)
	{
		delete enemy;
		enemy = nullptr;
	}

	int level = player.GetLevel();
	int i = rand() % 3 + 1;

	if (i == 1)
		enemy = new Enemy("Arkylian M", level, 10 + level * 4, 3 + level, level / 2, level * 6);
	else if (i == 2)
		enemy = new Enemy("Zenomorf", level, 8 + level * 3, 6 + level, 0, level * 6);
	else
		enemy = new Enemy("RALPH, the dog eater", level, 12 + level * 5, 2 + level, level / 2, level * 6);

	enemy->PrintEnemyStats();

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
	int levelBefore = player.GetLevel();

	player.LevelUp();

	if (player.GetLevel() > levelBefore)
	{
		std::cout << "Level UP! Now level " << player.GetLevel() << std::endl;
	}
	else
	{
		std::cout << "Not enough EXP" << std::endl;
	}
}

void Game::SkillUp()
{
	if (player.GetSkillPoints() <= 0)
	{
		std::cout << "Not enough Skill points" << std::endl;
		return;
	}

	while (player.GetSkillPoints() > 0)
	{
		std::cout << "You have " << player.GetSkillPoints() << " Skill points to use" << std::endl;
		std::cout << "--------Stats--------" << std::endl;
		std::cout << "0: Done (keep the remaining points)" << std::endl;
		std::cout << "1: Strength" << std::endl;
		std::cout << "2: Agility" << std::endl;
		std::cout << "3: Dexterity" << std::endl;
		std::cout << "4: Intelligence" << std::endl;
		std::cout << "5: Luck" << std::endl;

		std::cin >> choice;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			choice = -1;
		}

		if (choice == 0)
		{
			std::cout << "You saved " << player.GetSkillPoints() << " Skill points for later" << std::endl;
			return;
		}

		int pointsBefore = player.GetSkillPoints();
		player.AddStats(choice, 1);

		if (player.GetSkillPoints() < pointsBefore)
		{
			std::cout << "Stat increased!" << std::endl;
		}
	}

	std::cout << "You used all your Skill points" << std::endl;
}

void Game::CheatCode()
{
	//Para el dev
	int cheatEXP = 10000;
	int cheatHP = 900;

	int healthGained = 20;

	std::string code = "";
	std::string heal = "";

	std::cout << "Enter code: " << std::endl;

	std::cin >> code;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		code = "XD";
	}

	if (code == "CC")
	{
		player.AddExp(cheatEXP);
		player.AddHealth(cheatHP);
		std::cout << "Well cheated :). You gained: " << cheatEXP << " EXP" << std::endl;
		std::cout << "Well cheated :). You gained: " << cheatHP << " HP" << std::endl;

	}
	else if (heal == "heal")
	{
		player.AddHealth(healthGained);
		std::cout << "Well done :). You healed: " << healthGained << " HP" << std::endl;

	}
	else
	{
		std::cout << "Wrong code, try tiping: CC or heal" << std::endl;
	}
}
