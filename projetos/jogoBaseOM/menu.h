#pragma once
#include "libUnicornio.h"

enum ScreenView {
	MENU,
	INGAME,
	EXIT
};

class menu
{
public:
	menu();
	~menu();
	void inicializar();
	void atualizar();
	void desenhar();
	void finalizar();
	ScreenView GetStatusMenu();

private:
	ScreenView _screenView;
	BotaoSprite _btnStart, _btnExit;
};

