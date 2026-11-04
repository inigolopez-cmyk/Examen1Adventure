#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(std::string name, int l, int hp, int dmg, int def, int exp) :Character()
{
	InitCharacter(name);
	SetLevel(l);
	SetHP(hp);
	SetExp(exp);
	SetDamageMin(dmg / 2);
	SetDamageMax(dmg + 4);
	SetDefence(def);
}

Enemy::~Enemy()
{
}

void Enemy::InitEnemy()
{
	
}

void Enemy::PrintEnemyStats()
{
	PrintStats();

}
