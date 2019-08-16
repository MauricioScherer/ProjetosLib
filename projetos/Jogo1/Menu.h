#pragma once
#include "libUnicornio.h"

class Menu
{
public:
	Menu();
	~Menu();

	void Inicializar();
	void Finalizar();
	void Atualizar();
	void Desenhar();

private:
	BotaoSprite _btnVermelho;
	BotaoSprite _btnVerde;
	BotaoSprite _btnAzul;
};

