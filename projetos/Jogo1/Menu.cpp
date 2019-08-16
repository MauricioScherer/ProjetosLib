#include "Menu.h"



Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::Inicializar()
{
	gRecursos.carregarSpriteSheet("btnVermelho", "assets/sprite/sprBtnVermelho.png", 3, 1);
	gRecursos.carregarSpriteSheet("btnVerde", "assets/sprite/sprBtnVerde.png", 3, 1);
	gRecursos.carregarSpriteSheet("btnAzul", "assets/sprite/sprBtnAzul.png", 3, 1);

	_btnVermelho.setSpriteSheet("btnVermelho");
	_btnVerde.setSpriteSheet("btnVerde");
	_btnAzul.setSpriteSheet("btnAzul");

	_btnVermelho.setPos(gJanela.getLargura() / 6, gJanela.getAltura() / 4 - 100);
	_btnVerde.setPos(gJanela.getLargura() / 6, gJanela.getAltura() / 4);
	_btnAzul.setPos(gJanela.getLargura() / 6, gJanela.getAltura() / 4 + 100);
}

void Menu::Finalizar()
{
	gRecursos.descarregarSpriteSheet("btnVermelho");
	gRecursos.descarregarSpriteSheet("btnVerde");
	gRecursos.descarregarSpriteSheet("btnAzul");
}

void Menu::Atualizar()
{
	_btnVermelho.atualizar();
	_btnVerde.atualizar();
	_btnAzul.atualizar();

	if (_btnVermelho.estaClicado())
		gJanela.setCorDeFundo(255, 0, 0);

	if (_btnVerde.estaClicado())
		gJanela.setCorDeFundo(0, 255, 0);

	if (_btnAzul.estaClicado())
		gJanela.setCorDeFundo(0, 0, 255);

}

void Menu::Desenhar()
{
	_btnVermelho.desenhar();
	_btnVerde.desenhar();
	_btnAzul.desenhar();
}
