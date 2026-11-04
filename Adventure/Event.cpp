#include "Event.h"

Event::Event()
{
}

Event::~Event()
{
}

void Event::GenerateEvent(Player& p)
{
	srand(static_cast<unsigned int>(time(0)));
	int i = rand() % 10;

	switch (i)
	{
	case 7:
		std::cout << "Keep Traveling..." << std::endl;
		break;

	case 5:
		std::cout << "Puzzle Encounter" << std::endl;
		break;

	default:
		std::cout << "Enemy Encounter" << std::endl;
		EnemyEncounter(p);
		break;
	}
}

void Event::EnemyEncounter(Player& p)
{
	std::system("cls");
	int choice = 0;
	bool playerDefeated = false;
	bool enemyDefeated = false;
	bool escape = false;
	bool playerTurn = false;
	bool playerDefending = false;
	int firstTurn = rand() % 100 + 1;
	if (firstTurn >= 50 - p.GetLuck())
	{
		playerTurn = true;
	}
	else
	{
		playerTurn = false;
	}
	std::cout << "-----New Enemy Encounter-----" << std::endl;

	int level = p.GetLevel();
	int hp = p.GetLevel() * 10;
	int damage = rand() % p.GetDamageMin() + 1;
	int defence = rand() % p.GetLevel();
	int exp = hp;

	baseEnemy = new Enemy("", level, hp, damage, defence, exp);
	baseEnemy->PrintEnemyStats();

	while (!playerDefeated && !enemyDefeated && !escape)
	{
		int escapeRand = 0;
		int attackRoll = 0;

		if (playerTurn)
		{
			std::cout << "Choose your action" << std::endl;
			std::cout << "0: Escape" << std::endl;
			std::cout << "1: Attack" << std::endl;
			std::cout << "2: Defend" << std::endl;
			std::cout << "3: Player Sheet" << std::endl;
			std::cout << "4: Show Enemy Stats" << std::endl;

			std::cin >> choice;

			switch (choice)
			{
			case 0:
				escapeRand = (rand() % 100) + (p.GetLuck() + p.GetAgility()) / 2;
				if (escapeRand > 25)
				{
					std::cout << "Escaped...." << std::endl;
					escape = true;
				}
				break;

			case 1:
				std::system("cls");
				attackRoll = rand() % 100 + 1;
				if (attackRoll > 50 - (p.GetStrength() + p.GetDexterity()))
				{
					std::cout << "Player hits Enemy!" << std::endl;
					baseEnemy->TakeDamage(p.DoDamage());
				}
				break;

			case 2:
				playerDefending = true;
				break;

			case 3:
				p.PrintPlayerStats();
				break;

			case 4:
				baseEnemy->PrintEnemyStats();
				break;

			default:
				std::cout << "Invalid Option" << std::endl;
				break;
			}
			playerTurn = false;

		}

		else
		{
			std::cout << "-------ENEMY TURN-------" << std::endl;

			if (!baseEnemy->IsAlive())
			{
				enemyDefeated = true;
				std::cout << "Enemy Defeated" << std::endl;
				std::cout << "Exp: " << baseEnemy->GetExp() << std::endl;
				p.AddExp(baseEnemy->GetExp());
			}

			else
			{
				int enemyAttackRoll = rand() % 100 + 1 - p.GetLuck();

				if (playerDefending)
				{
					if (enemyAttackRoll > 75)
					{
						std::cout << "Enemy hits player!" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}

					else
					{
						std::cout << "Enemy misses!" << std::endl;
					}
				}

				else
				{
					if (enemyAttackRoll > 45)
					{
						std::cout << "Enemy hits player!" << std::endl;
						p.TakeDamage(baseEnemy->DoDamage());
					}

					else
					{
						std::cout << "Enemy misses!" << std::endl;
					}
				}
			}
			playerTurn = true;

		}
	}


}

void Event::PuzzleEncounter(Player& p)
{
}
