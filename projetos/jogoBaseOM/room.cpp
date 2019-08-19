#include "room.h"

room::room()
{

}

room::~room()
{
}

void room::Inicializar()
{
	gRecursos.carregarSpriteSheet("background", "assets/sprite/level/background_1.png");

	_background.setSpriteSheet("background");
}

void room::Desenhar()
{
	_background.desenhar(gJanela.getLargura() / 2, gJanela.getAltura() / 2);
}

void room::Finalizar()
{
	gRecursos.descarregarTudo();
}
