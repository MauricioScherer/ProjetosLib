#pragma once
#include "libUnicornio.h"

class Obstaculo
{
public:
	Obstaculo();
	~Obstaculo();

	void inicializar(bool r, string n);
	void finalizar();
	void desenhar();
	void atualizar();
	void reiniciar(bool r_2, string n_2, int numanim_2, int numframes_2, int posx, int posy);
	Sprite *getSprite();
	float getX();
	float getY();

private:

	string nome;
	float x, y, velocidade;
	Sprite sprite;
	bool raio;

};

