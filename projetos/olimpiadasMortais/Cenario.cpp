#include "Cenario.h"
#include "Personagem.h"


Cenario::Cenario()
{
}


Cenario::~Cenario()
{
}

void Cenario::inicializar(bool j, string n, string path)
{
	nome = n;
	recursos.carregarSpriteSheet(nome, path);
	sprite.setSpriteSheet(nome);
}

void Cenario::finalizar()
{

}

void Cenario::desenhar()
{
	sprite.desenhar(x, y);
	atualizar();
}

void Cenario::atualizar()
{
	if ()
	{
		
	}
}
