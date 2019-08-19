#include "menu.h"

menu::menu()
{
}

menu::~menu()
{
}

void menu::inicializar()
{
	_screenView = MENU;

	gRecursos.carregarSpriteSheet("btnStart", "assets/sprite/btnStart.png", 3, 1);
	gRecursos.carregarSpriteSheet("btnExit", "assets/sprite/btnExit.png", 3, 1);

	_btnStart.setSpriteSheet("btnStart");
	_btnExit.setSpriteSheet("btnExit");

	_btnStart.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2 - 100);
	_btnExit.setPos(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void menu::atualizar()
{
	_btnStart.atualizar();
	_btnExit.atualizar();
}

void menu::desenhar()
{
	_btnStart.desenhar();
	_btnExit.desenhar();	

	if (_btnStart.estaClicado())
		_screenView = INGAME;
	else if (_btnExit.estaClicado())
		_screenView = EXIT;
}

void menu::finalizar()
{
	gRecursos.descarregarSpriteSheet("btnStart");
	gRecursos.descarregarSpriteSheet("btnExit");
}

ScreenView menu::GetStatusMenu()
{
	return _screenView;
}
