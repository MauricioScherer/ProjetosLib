#pragma once
#include "libUnicornio.h"
#include "menu.h"



class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	menu _menu;
};

