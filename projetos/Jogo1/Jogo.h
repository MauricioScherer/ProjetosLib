#pragma once
#include "Menu.h"
#include "PersonagemNovo.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	Menu menu;
	PersonagemNovo player;
};

