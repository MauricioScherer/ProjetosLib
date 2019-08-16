#pragma once
#include "libUnicornio.h"

class Personagem2
{
public:

	Personagem2();
	~Personagem2();

	void inicializar(string n, string path, int numanim, int numframes);
	void finalizar();
	void desenhar();
	void atualizar();
	void colidir();
	void vencedor();
	void reiniciar(string n, string path, int numanim_2, int numframes_2, int posx, int posy, bool venceu_rein);
	void setaudio(string nomesom);
	Sprite *getSprite();
	float getX();
	float getY();

private:

	string nome;
	float x, y, velocidade, comando, controle;
	Sprite sprite;
	bool jogador, pulou, descendo, abaixou, lado, correndo_ia, venceu, pulouIA, descendoIA;
	Som som;
};
