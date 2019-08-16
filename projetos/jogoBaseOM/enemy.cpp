#include "enemy.h"



enemy::enemy()
{
}


enemy::~enemy()
{
}

#pragma region Life
int enemy::GetLife()
{
	return _life;
}

void enemy::SetLife(int p_life)
{
	_life = p_life;
}
#pragma endregion

#pragma region Damage
int enemy::GetDamage()
{
	return _damage;
}

void enemy::SetDamage(int p_damage)
{
	_damage = p_damage;
}
#pragma endregion
