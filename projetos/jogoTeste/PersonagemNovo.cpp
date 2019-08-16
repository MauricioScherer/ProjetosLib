#include "PersonagemNovo.h"



PersonagemNovo::PersonagemNovo()
{
	vel = 0.2;
	x = 0;
	y = 0;
}


PersonagemNovo::~PersonagemNovo()
{
}

void PersonagemNovo::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

void PersonagemNovo::setVel(float vel)
{
	this->vel = vel;
}

void PersonagemNovo::setSpriteSheet(string spritesheet)
{
	sprite.setSpriteSheet(spritesheet);
}

void PersonagemNovo::moverDir()
{
	x += vel;
	sprite.setAnimacao(CAMINHANDO_DIR);
}

void PersonagemNovo::moverEsq()
{
	x -= vel;
	sprite.setAnimacao(CAMINHANDO_ESQ);
}

void PersonagemNovo::moverCima()
{
	y -= vel;
	sprite.setAnimacao(CAMINHANDO_CIMA);
}

void PersonagemNovo::moverBaixo()
{
	y += vel;
	sprite.setAnimacao(CAMINHANDO_BAIXO);
}

void PersonagemNovo::girar()
{
	sprite.setAnimacao(GIRANDO);
}

void PersonagemNovo::ficarParado()
{
	sprite.setAnimacao(PARADO);
}

void PersonagemNovo::animar()
{
	sprite.avancarAnimacao();
}

void PersonagemNovo::desenhar()
{
	sprite.desenhar(x, y);
}
