#include "player.h"



player::player()
{
}


player::~player()
{
}

#pragma region Life
int player::GetLife()
{
	return _life;
}

void player::SetLife(int p_life)
{
	_life = p_life;
}
#pragma endregion

#pragma region Xp
int player::GetXp()
{
	return _xp;
}

void player::SetXp(int p_xp)
{
	_xp = p_xp;
}
#pragma endregion

#pragma region Mana
int player::GetMana()
{
	return _mana;
}

void player::SetMana(int p_mana)
{
	_mana = p_mana;
}
#pragma endregion

#pragma region Level
int player::GetLevel()
{
	return _level;
}

void player::SetLevel(int p_level)
{
	_level = p_level;
}
#pragma endregion

#pragma region Damage
int player::GetDamage()
{
	return _damage;
}

void player::SetDamage(int p_damage)
{
	_damage = p_damage;
}
#pragma endregion