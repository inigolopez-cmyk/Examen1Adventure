#pragma once
#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>
#include <cstdlib>
#include "Enemy.h"
#include "Player.h"

class Event
{
private:
	int numOfEvents;
	Enemy* baseEnemy;
	bool puzzleCompleted = false;

public:
	Event();
	~Event();

	void GenerateEvent(Player& p);
	void EnemyEncounter(Player& p);
	void PuzzleEncounter(Player& p);

	bool GetPuzzleCompleted() { return puzzleCompleted; }
};

