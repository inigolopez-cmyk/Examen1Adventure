#pragma once
#include "Character.h"
class Enemy :
    public Character
{
private:

public:
    Enemy();
    Enemy(std::string name, int l, int hp, int dmg, int def, int exp);
    ~Enemy();
    void InitEnemy();
    void PrintEnemyStats();

};

