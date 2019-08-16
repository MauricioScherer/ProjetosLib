#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false, "jogoTeste");

	menu.Inicializar();
}

void Jogo::finalizar()
{
	menu.Finalizar();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		menu.Atualizar();
		menu.Desenhar();

		uniTerminarFrame();
	}
}