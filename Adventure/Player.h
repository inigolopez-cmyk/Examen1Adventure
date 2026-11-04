#pragma once
#include "Character.h"
#include <string>
#include <fstream>

class Player :
	public Character
{
private:
	int strength;
	int agility;
	int dexterity;
	int intelligence;
	int luck;

	int MaxXP;
	int skillPoints;

public:
	Player();
	~Player();
	void InitPlayer(std::string name);
	void PrintPlayerStats();
	void LevelUp();
	void AddStats(int stat, int value);
	void UpdateValues();
	void LoadStats(const std::string& filename);
	std::string SaveStats();

	//Gets
	int GetStrength() { return strength;  }
	int GetAgility() { return agility; }
	int GetDexterity() { return dexterity; }
	int GetIntelligence() { return intelligence; }
	int GetLuck() { return luck; }
	int GetSkillPoints() { return skillPoints;  }


	//Sets
	void SetStrength(int s) { strength = s;  }
	void SetAgility(int a) { agility = a;  }
	void SetDexterity(int d) { dexterity = d; }
	void SetIntelligence(int i) { intelligence = i; }
	void SetLuck(int l) { luck = l; }
	void SetSkillPoints(int sp) { skillPoints = sp;  }
};

