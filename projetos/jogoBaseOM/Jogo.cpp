#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);

	_menu.inicializar();
}

void Jogo::finalizar()
{
	_menu.finalizar();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		if (_menu.GetStatusMenu() == MENU)
		{
			//_menu.atualizar();
			_menu.desenhar();
		}
		else
		{

		}

		uniTerminarFrame();
	}
}