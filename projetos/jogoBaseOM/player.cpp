#include "player.h"



player::player()
{
	_speed = 0.2f;
	_xPos = 0;
	_yPos = 0;
}


player::~player()
{
}

void player::Inicializar()
{
	gRecursos.carregarSpriteSheet("player", "assets/sprite/character/sprPlayer.png", 5, 4);
	gRecursos.getSpriteSheet("player")->setNumFramesDaAnimacao(0,1);
	_sprPlayer.setSpriteSheet("player");
	setPos(300, 300);
	setSpeed(0.8f);
}

void player::Finalizar()
{
	gRecursos.descarregarSpriteSheet("player");
}

void player::setPos(int p_xPos, int p_yPos)
{
	_xPos = p_xPos;
	_yPos = p_yPos;
}

void player::setSpeed(float p_vel)
{
	_speed = p_vel;
}

void player::setSpriteSheet(string p_sprPlayer)
{
	_sprPlayer.setSpriteSheet(p_sprPlayer);
}

void player::animar()
{
	_sprPlayer.avancarAnimacao();
}

void player::desenhar()
{
	_sprPlayer.desenhar(_xPos, _yPos);
}

void player::Move()
{
	float larguraTela = gJanela.getLargura();
	float alturaTela = gJanela.getAltura();

	if (gTeclado.segurando[TECLA_DIR] && GetPosX() < larguraTela)
	{
		_xPos += _speed;
		_sprPlayer.setAnimacao(CAMINHANDO_DIR);
	}
	else if (gTeclado.segurando[TECLA_ESQ] && GetPosX() > 0)
	{
		_xPos -= _speed;
		_sprPlayer.setAnimacao(CAMINHANDO_ESQ);
	}
	else if (gTeclado.segurando[TECLA_CIMA] && GetPosY() > 0)
	{
		_yPos -= _speed;
		_sprPlayer.setAnimacao(CAMINHANDO_CIMA);
	}
	else if (gTeclado.segurando[TECLA_BAIXO] && GetPosY() < alturaTela)
	{
		_yPos += _speed;
		_sprPlayer.setAnimacao(CAMINHANDO_BAIXO);
	}
	else
		_sprPlayer.setAnimacao(PARADO);
}

float player::GetPosX()
{
	return _xPos;
}

float player::GetPosY()
{
	return _yPos;
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