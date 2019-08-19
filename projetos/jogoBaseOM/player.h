#pragma once
#include "libUnicornio.h"

enum PersonagemAnim
{
	PARADO,
	CAMINHANDO_BAIXO,
	CAMINHANDO_ESQ,
	CAMINHANDO_DIR,
	CAMINHANDO_CIMA,
	GIRANDO
};

class player
{
public:
	player();
	~player();

	void Inicializar();
	void Finalizar();
	void animar();
	void desenhar();

	void setPos(int p_xPos, int p_yPos);
	void setSpeed(float p_vel);
	void setSpriteSheet(string p_sprPlayer);
	void Move();
	float GetPosX();
	float GetPosY();

	int GetLife();
	void SetLife(int p_life);

private:
	int _life;
	Sprite _sprPlayer;
	float _xPos, _yPos;
	float _speed;
};

