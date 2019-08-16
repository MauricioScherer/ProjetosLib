#include "Personagem2.h"

Personagem2::Personagem2()
{
}


Personagem2::~Personagem2()
{
}

void Personagem2::inicializar(string n, string path, int numanim, int numframes)
{
	nome = n;
	pulou = false;			//Validar se já pulou. Inicia em pé, então inicia false.
	descendo = false;		//Validar se está descendo, se sim, não pode pular novamente, então incia em false.
	venceu = false;

	recursos.carregarSpriteSheet(nome, path, numanim, numframes);
	sprite.setSpriteSheet(nome);

	x = 150;				//Local de inicialização do jogador na horizontal X.
	y = 460;				//Local de inicialização do jogador na vertical Y.

	velocidade = 15;		//Velocidade de movimento.

	sprite.setVelocidadeAnimacao(5);

	comando = 2; //comando obrigando a variação dos comandos e possibilitando o inicio com qualquer tecla 
}

void Personagem2::desenhar()
{

	sprite.desenhar(x, y);	//Desenhar personagens
	atualizar();
}

void Personagem2::finalizar()
{

}

void Personagem2::atualizar()
{

	//codigos do pulo: inicio
	//
	if (!venceu)
	{
		if (teclado.pressionou[TECLA_CTRL_DIR] && !pulou)
		{
			sprite.setSpriteSheet("chubaccapular");
			sprite.setAnimacao(0);
			pulou = true;
			descendo = false;
		}

		if (pulou)
		{
			if (teclado.segurando[TECLA_CTRL_DIR] && !descendo && y > 200)
			{
				y -= 2.5;
				x += 0.78;
			}
		}

		if (y <= 360 || teclado.soltou[TECLA_CTRL_DIR])
		{
			descendo = true;
		}

		if (descendo)
		{
			if (y < 460)
			{
				y += 2.5;
				x += 0.78;
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

		if ((teclado.soltou[TECLA_DIR]) && ((comando == 0) || (comando == 2)) && y == 460)
		{
			x += velocidade;
			comando = 1;
		}

		else if ((teclado.soltou[TECLA_ESQ]) && ((comando == 1) || (comando == 2)) && y == 460)
		{
			x += velocidade;
			comando = 0;
		}
	}
	//
	//codigos de corrida: fim


	//velocidade da esteira
	//
	if (y == 460 && !venceu && x < janela.getLarguraTela() / 2)
	{
		x -= 1;
	}

	if (y == 460 && !venceu && x > janela.getLarguraTela() / 2)
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


//colisao com o personagem 2
//
void Personagem2::colidir()
{
	x -= 10;
	sprite.setSpriteSheet("choque");

	som.tocar();
}

//condição para vitória, mudando sprite e tornando venceu como true para que os botões não tenham mais funcionabilidade
//
void Personagem2::vencedor()
{
	sprite.setSpriteSheet("shuvencer");
	sprite.avancarAnimacao();
	sprite.setVelocidadeAnimacao(2);
	venceu = true;
}

Sprite *Personagem2::getSprite()
{
	return &sprite;
}

float Personagem2::getX()
{
	return x;
}

float Personagem2::getY()
{
	return y;
}

void Personagem2::setaudio(string nomesom)
{
	som.setAudio(nomesom);

	som.setVolume(10);
}

void Personagem2::reiniciar(string n_2, string path_2, int numanim_2, int numframes_2, int posx, int posy, bool venceu_rein)
{
	nome = n_2;
	venceu = venceu_rein;
	x = posx;
	y = posy;
}

