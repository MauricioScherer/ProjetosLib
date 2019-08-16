#pragma once
#include "libUnicornio.h"
class Raio_da_morte
{
public:
	Raio_da_morte();
	~Raio_da_morte();

	void inicializar();
	void finalizar();
	void desenhar();
	void atualizar();

private:

	float x, y;
	Sprite sprite;

};

