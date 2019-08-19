#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(600, 600, false);

	_classMenu.inicializar();
	_classRoom.Inicializar();
	_classPlayer.Inicializar();
}

void Jogo::finalizar()
{
	_classMenu.finalizar();
	_classRoom.Finalizar();
	_classPlayer.Finalizar();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (_classMenu.GetStatusMenu())
		{
		case MENU:
			_classMenu.atualizar();
			_classMenu.desenhar();
			break;
		case INGAME:
			_classRoom.Desenhar();
			_classPlayer.animar();
			_classPlayer.Move();
			_classPlayer.desenhar();
			break;
		case EXIT:
			break;
		default:
			break;
		}

		uniTerminarFrame();
	}
}