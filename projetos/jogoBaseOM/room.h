#pragma once
#include "enemy.h"

class room
{
public:
	room();
	~room();
		

private:
	int _qtPorta, _qtEnemy;

	enemy _enemy;
};

