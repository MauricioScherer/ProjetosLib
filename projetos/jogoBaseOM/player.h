#pragma once
class player
{
public:
	player();
	~player();

	int GetLife();
	void SetLife(int p_life);
	int GetXp();
	void SetXp(int p_xp);
	int GetMana();
	void SetMana(int p_mana);
	int GetLevel();
	void SetLevel(int p_level);
	int GetDamage();
	void SetDamage(int p_damage);

private:
	int _life, _xp, _mana, _level, _damage;
};

