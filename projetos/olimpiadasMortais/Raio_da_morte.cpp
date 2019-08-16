#include "Raio_da_morte.h"


Raio_da_morte::Raio_da_morte()
{
}


Raio_da_morte::~Raio_da_morte()
{
}

void Raio_da_morte::inicializar()
{

	recursos.carregarSpriteSheet("placar", "./dados/spritesheets/placar_largada.png", 1, 3);
	recursos.carregarSpriteSheet("placar_go", "./dados/spritesheets/placar_goooo.png", 1, 2);

	sprite.setSpriteSheet("placar");
	sprite.setVelocidadeAnimacao(.5);

	x = 300;
	y = 600;
}

void Raio_da_morte::finalizar()
{

}

void Raio_da_morte::desenhar()
{
	sprite.desenhar(x, y);
	atualizar();
}

void Raio_da_morte::atualizar()
{
	if (sprite.terminouAnimacao())
	{
		sprite.setSpriteSheet("placar_go");
		sprite.setVelocidadeAnimacao(3);
	}
}