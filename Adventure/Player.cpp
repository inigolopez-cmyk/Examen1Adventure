#include "Player.h"
#include "Game.h"

Player::Player() :Character()
{
	this->strength = 5;
	this->agility = 5;
	this->dexterity = 5;
	this->intelligence = 5;
	this->luck = 5;
	this->MaxXP = 1;
}

Player::~Player()
{
}

void Player::InitPlayer(std::string name)
{
	InitCharacter(name);
	SetLevel(1);
	SetExp(0);
	SetHP((this->intelligence * 2) / (this->dexterity -3));
	SetDamageMin(this->strength - 2);
	SetDamageMax(this->strength * 2);
	SetDefence((this->agility * 2) / (this->luck -3));

}

void Player::PrintPlayerStats()
{
	PrintStats();
	std::cout << "--------------------" << std::endl;
	std::cout << "Strength: " << this->strength << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Dexterity: " << this->dexterity << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
	std::cout << "Exp required to level up: " << this->MaxXP << std::endl;
}

void Player::LevelUp()
{
	while (GetExp() >= MaxXP)
	{
		SetExp(GetExp() - MaxXP);
		SetLevel(GetLevel() + 1);
		MaxXP = GetLevel() * 10;
		skillPoints++;
	}
}

void Player::AddStats(int stat, int value)
{
	if (skillPoints < value)
	{
		std::cout << "Not Enough Points" << std::endl;
	}
	else
	{
		switch (stat)
		{
		case 1:
			this->strength += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 2:
			this->agility += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 3:
			this->dexterity += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 4:
			this->intelligence += value;
			skillPoints -= value;
			UpdateValues();
			break;
		case 5:
			this->luck += value;
			skillPoints -= value;
			UpdateValues();
			break;
		default:
			std::cout << "This stat does not exist" << std::endl;
			break;
		}
	}
}

void Player::UpdateValues()
{
	SetHP((this->intelligence * 2) / (this->dexterity - 3));
	SetDamageMin(this->strength - 2);
	SetDamageMax(this->strength * 2);
	SetDefence((this->agility * 2) / (this->luck - 3));
}

void Player::LoadStats(const std::string& filename)
{
	std::ifstream inFile(filename);
	if (!inFile.is_open())
	{
		std::cerr << "ERROR: Can not open file" << filename << std::endl;
		return;
	}
	std::string name = "";
	int l;
	int xp;
	int hp;
	int dmin;
	int dmax;
	int d;
	int sp;
	//std::getline(inFile, name);
	inFile 
		>> name 
		>> l 
		>> hp 
		>> xp 
		>> dmin 
		>> dmax 
		>> d 
		>> strength 
		>> agility 
		>> dexterity 
		>> intelligence 
		>> luck 
		>> sp;
	inFile.close();

	SetName(name);
	SetLevel(l);
	SetHP(hp);
	SetExp(xp);
	SetDamageMin(dmin);
	SetDamageMax(dmax);
	SetDefence(d);
	SetSkillPoints(sp);
}

std::string Player::SaveStats()
{
	return this->GetName() + " " + 
		std::to_string(this->GetLevel()) + " " +
		std::to_string(this->GetExp()) + " " +
		std::to_string(this->GetHP()) + " " +
		std::to_string(this->GetDamageMin()) + " " +
		std::to_string(this->GetDamageMax()) + " " +
		std::to_string(this->GetDefence()) + " " +
		std::to_string(this->GetStrength()) + " " +
		std::to_string(this->GetAgility()) + " " +
		std::to_string(this->GetDexterity()) + " " +
		std::to_string(this->GetIntelligence()) + " " +
		std::to_string(this->GetLuck()) + " " +
		std::to_string(this->GetSkillPoints());
}

