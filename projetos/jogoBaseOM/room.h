#pragma once
#include "enemy.h"
#include "libUnicornio.h"

class room
{
public:
	room();
	~room();

	void Inicializar();
	void Desenhar();
	void Finalizar();		

private:
	Sprite _background;
};

