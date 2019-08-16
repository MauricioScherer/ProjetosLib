#include "Personagem.h"

Personagem::Personagem()
{
}


Personagem::~Personagem()
{
}

void Personagem::inicializar(int player, string n, string path, int numanim, int numframes)
{
	nome = n;
	pulou = false;			//Validar se já pulou. Inicia em pé, então inicia false.
	descendo = false;		//Validar se está descendo, se sim, não pode pular novamente, então incia em false.
	venceu = false;

	gRecursos.carregarSpriteSheet(nome, path, numanim, numframes);
	sprite.setSpriteSheet(nome);

	if (player == 1)
	{
		x = 90;				//Local de inicialização do jogador na horizontal X.
		y = 560;			//Local de inicialização do jogador na vertical Y.
		player1 = 1;
	}

	if (player == 2)
	{
		x = 150;				//Local de inicialização do jogador na horizontal X.
		y = 460;				//Local de inicialização do jogador na vertical Y.
		player2 = 2;
	}

	velocidade = 15;		//Velocidade de movimento.

	sprite.setVelocidadeAnimacao(5);

	comando = 2; //comando obrigando a variação dos comandos e possibilitando o inicio com qualquer tecla 
}

void Personagem::desenhar()
{

	sprite.desenhar(x, y);	//Desenhar personagens
	atualizar();
}

void Personagem::finalizar()
{
	gRecursos.descarregarTudo();

	uniFinalizar();
}

void Personagem::atualizar()
{
	if (player1 == 1)
	{

		//codigos do pulo: inicio
		//
		if (!venceu)
		{
			if (gTeclado.pressionou[TECLA_ESPACO] && !pulou)
			{
				sprite.setSpriteSheet("pular");
				sprite.setAnimacao(0);
				pulou = true;
				descendo = false;
			}

			if (pulou)
			{
				if (gTeclado.segurando[TECLA_ESPACO] && !descendo && y > 300)
				{
					y -= 2.5;
					x += 0.9;
				}
			}

			if (y <= 460 || gTeclado.soltou[TECLA_ESPACO])
			{
				descendo = true;
			}

			if (descendo)
			{
				if (y < 560)
				{
					y += 2.5;
					x += 0.9;
				}

				else
				{
					sprite.setSpriteSheet("branco");
					sprite.setAnimacao(0);
					pulou = false;
					descendo = false;
				}

			}
		}
		//
		//codigos do pulo: fim


		//codigos de corrida: inicio
		//
		if (!venceu)
		{

			if ((gTeclado.soltou[TECLA_D]) && ((comando == 0) || (comando == 2)) && y == 560)
			{
				x += velocidade;
				comando = 1;
			}

			else if ((gTeclado.soltou[TECLA_A]) && ((comando == 1) || (comando == 2)) && y == 560)
			{
				x += velocidade;
				comando = 0;
			}
		}
		//
		//codigos de corrida: fim


		//velocidade da esteira
		//
		if (y == 560 && !venceu && x < gJanela.getLargura() / 2)
		{
			x -= 1;
		}

		if (y == 560 && !venceu && x > gJanela.getLargura() / 2)
		{
			x -= 1.3;
		}
		//
		//velocidade da esteira


		//comando simulando corrida na esteira: inicio
		//
		if (!venceu)
		{
			sprite.avancarAnimacao();
		}
		//
		//comando simulando corrida na esteira: fim

	}

	if (player2 == 2)
	{
		//codigos do pulo: inicio
		//
		if (!venceu)
		{
			if (gTeclado.pressionou[TECLA_CTRL_DIR] && !pulou)
			{
				sprite.setSpriteSheet("chubaccapular");
				sprite.setAnimacao(0);
				pulou = true;
				descendo = false;
			}

			if (pulou)
			{
				if (gTeclado.segurando[TECLA_CTRL_DIR] && !descendo && y > 200)
				{
					y -= 2.5;
					x += 0.9;
				}
			}

			if (y <= 360 || gTeclado.soltou[TECLA_CTRL_DIR])
			{
				descendo = true;
			}

			if (descendo)
			{
				if (y < 460)
				{
					y += 2.5;
					x += 0.9;
				}

				else
				{
					sprite.setSpriteSheet("chubacca");
					sprite.setAnimacao(0);
					pulou = false;
					descendo = false;
				}

			}
		}
		//
		//codigos do pulo: fim


		//codigos de corrida: inicio
		//
		if (!venceu)
		{

			if ((gTeclado.soltou[TECLA_DIR]) && ((comando == 0) || (comando == 2)) && y == 460)
			{
				x += velocidade;
				comando = 1;
			}

			else if ((gTeclado.soltou[TECLA_ESQ]) && ((comando == 1) || (comando == 2)) && y == 460)
			{
				x += velocidade;
				comando = 0;
			}
		}
		//
		//codigos de corrida: fim


		//velocidade da esteira
		//
		if (y == 460 && !venceu && x < gJanela.getLargura() / 2)
		{
			x -= 1;
		}

		if (y == 460 && !venceu && x > gJanela.getLargura() / 2)
		{
			x -= 1.3;
		}
		//
		//velocidade da esteira

		//comando simulando corrida na esteira: inicio
		//
		if (!venceu)
		{
			sprite.avancarAnimacao();
		}
		//
		//comando simulando corrida na esteira: fim
	}
}

//colisao com o personagem
//
void Personagem::colidir()
{
	x -= 10;
	sprite.setSpriteSheet("choque");

	som.tocar();
}

//condição para vitória hansolo, mudando sprite e tornando venceu como true para que os botões não tenham mais funcionabilidade
//
void Personagem::vencedor_han()
{
	sprite.setSpriteSheet("dancavitoria");
	sprite.avancarAnimacao();
	sprite.setVelocidadeAnimacao(2);
	venceu = true;
}

//condição para vitória shu, mudando sprite e tornando venceu como true para que os botões não tenham mais funcionabilidade
//
void Personagem::vencedor_shu()
{
	sprite.setSpriteSheet("shuvencer");
	sprite.avancarAnimacao();
	sprite.setVelocidadeAnimacao(2);
	venceu = true;
}


Sprite *Personagem::getSprite()
{
	return &sprite;
}


float Personagem::getX()
{
	return x;
}


float Personagem::getY()
{
	return y;
}

void Personagem::setaudio(string nomesom)
{
	som.setAudio(nomesom);

	som.setVolume(10);
}

void Personagem::reiniciar(string n_2, int numanim_2, int numframes_2, int posx, int posy, bool venceu_rein)
{
	nome = n_2;
	venceu = venceu_rein;
	x = posx;
	y = posy;

}


