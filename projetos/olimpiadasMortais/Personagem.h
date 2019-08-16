#pragma once
#include "libUnicornio.h"

class Personagem
{
public:

	Personagem();
	~Personagem();

	void inicializar(int player, string n, string path, int numanim, int numframes);
	void finalizar();
	void desenhar();
	void atualizar();
	void colidir();
	void vencedor_han();
	void vencedor_shu();
	void reiniciar(string n, int numanim_2, int numframes_2, int posx, int posy, bool venceu_rein);
	void setaudio(string nomesom);
	Sprite *getSprite();
	float getX();
	float getY();

private:

	string nome;
	int player1, player2;
	float x, y, velocidade, comando, controle;
	Sprite sprite;
	bool pulou, descendo, venceu;
	Som som;
};

