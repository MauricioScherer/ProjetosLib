#pragma once
#include "libUnicornio.h"
#include "menu.h"
#include "room.h"
#include "player.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	menu _classMenu;
	room _classRoom;
	player _classPlayer;
};

