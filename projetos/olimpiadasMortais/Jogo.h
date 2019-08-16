#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "Personagem2.h"
#include "Obstaculo.h"

enum Status { apresentacao, menu, menuContinuar, jogando, teclado_players };

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();
	void executar();
	void reiniciar(int posxfundo, int posxl, int posxc, int posxe, int posxe2, int posyvir,
				   bool hanvenceu_rein, bool shuvenceu_rein, bool cond_largada_rein, bool virada_1, bool virada_2, bool sair_rein);

private:
	Sprite fundo, esteira, intro, opcaomenu, largada, hanlargada, shubalargada,tutorial, apresentacao_inicio, indicador,
		   largadago, chegada, placar_chegadahan, placar_chegadashu, viradahan, viradashu, menuvirada, choque, raio_novinho;
	Personagem branco, pular, vencer, levar_choque, shuba, shubapular, shuvencer;
	Obstaculo raio, raio2;
	float xf, xe, xe2, yf, xl, yl, xc, yvir, ymenuvir, xr, yr;
	bool entrou, hanvenceu, shuvenceu, cond_largada, player1_vitoria, player2_vitoria;
	//Musica musicamenu, musicafundo, musicavitoria;
	Status status;		
};