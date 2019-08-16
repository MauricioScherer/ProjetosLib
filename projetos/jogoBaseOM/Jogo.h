#pragma once
#include "libUnicornio.h"

enum ScreenView {
	MENU,
	INGAME
};

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	ScreenView _screenView;
};

