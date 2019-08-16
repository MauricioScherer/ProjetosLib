#include "Obstaculo.h"


Obstaculo::Obstaculo()
{
}


Obstaculo::~Obstaculo()
{
}

void Obstaculo::inicializar(bool r, string n)
{
	nome = n;
	raio = r;

	//aleatoriedade na velocidade dos obstaculos
	//
	velocidade = (rand() % 3) + 1;	
	
	sprite.setSpriteSheet("raio");
	sprite.setVelocidadeAnimacao(2);

	//aleatoriedade na posição dos obstaculos
	//
	x = (rand() % 500) + gJanela.getLargura() + sprite.getLargura() / 3;
	y = 585;

	//mudança de posição em "y" e aleatoriedade para os obstaculos do player 2
	//
	if (!raio)
	{
		x = (rand() % 450) + gJanela.getLargura() + sprite.getLargura() / 3;
		y = 485;
	}

}

void Obstaculo::finalizar()
{

}

void Obstaculo::desenhar()
{
	sprite.desenhar(x, y);
	atualizar();
}

void Obstaculo::atualizar()
{
	//atualização das condições do obstaculo para o player 1
	//
	if (raio)
	{
		x -= velocidade;
		sprite.avancarAnimacao();

		if (x < sprite.getLargura())
		{
			x = (rand() % 500) + gJanela.getLargura() + sprite.getLargura() / 2;
			velocidade = (rand() % 3) + 1;
		}
	}

	//atualização das condições do obstaculo para o player 2
	//
	else
	{
		x -= velocidade;
		sprite.avancarAnimacao();

		if (x < sprite.getLargura())
		{
			x = (rand() % 450) + gJanela.getLargura() + sprite.getLargura() / 2;
			velocidade = (rand() % 3) + 1;
		}
	}
}

Sprite *Obstaculo::getSprite()
{
	return &sprite;
}

float Obstaculo::getX()
{
	return x;
}

float Obstaculo::getY()
{
	return y;
}

void Obstaculo::reiniciar(bool r_2, string n_2, int numanim_2, int numframes_2, int posx, int posy)
{
	raio = r_2;
	nome = n_2;
	x = posx;
	y = posy;
}