#pragma once
#include <iostream>
#include <fstream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Event.h"


class Game
{
private:
	Player player;
	Enemy* enemy;
	Event ev;
	int choice;
	bool playing;

public:
	Game();
	virtual ~Game();
	void InitGame();
	void MainMenu();

	void Travel();

	void SavePlayer();
	void LoadPlayer();
	void NewPlayer();
	void NewEnemy();
	void PrintPlayerStats();
	void LevelUp();
	void SkillUp();

	bool GetPlaying();
};

