#pragma once
class enemy
{
public:
	enemy();
	~enemy();

	int GetLife();
	void SetLife(int p_life);
	int GetDamage();
	void SetDamage(int p_damage);

private:
	int _life, _damage;

	enum TypeEnemy
	{
		MONSTER_1,
		MONSTER_2,
		MONSTER_3
	};
};

