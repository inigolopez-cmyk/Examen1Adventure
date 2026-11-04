#pragma once
#include <iostream>

class Character
{
private:
	std::string name;
	int level;
	int hp;
	int exp;
	int damageMin;
	int damageMax;
	int defence;

protected:

public:
	Character();
	virtual ~Character();
	void InitCharacter(std::string N);
	void PrintStats();
	void TakeDamage(int d);
	const int DoDamage();
	bool IsAlive();

	//Gets
	std::string GetName() { return name; }
	int GetLevel() { return level; }
	int GetHP() { return hp; }
	int GetExp() { return exp; }
	int GetDamageMin() { return damageMin; }
	int GetDamageMax() { return damageMax; }
	int GetDefence() { return defence; }

	//Sets
	void SetName(std::string n) { name = n; };
	void SetLevel(int l) { level = l; }
	void SetHP(int h) { hp = h; }
	void SetExp(int e) { exp = e; }
	void SetDamageMin(int min) { damageMin = min; }
	void SetDamageMax(int max) { damageMax = max; }
	void SetDefence(int d) { defence = d; }

	void AddExp(int xp) { exp += xp; }
};

