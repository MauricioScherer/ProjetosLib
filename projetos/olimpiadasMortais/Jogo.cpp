#include "Jogo.h"

Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}


void Jogo::inicializar()
{
	uniInicializar(1280, 720, true, "Olimpíadas Star Wars");

	//condições iniciais
	//
	status = apresentacao;
	xf = 2000;
	xe = 1280;
	xe2 = 3840;
	yf = 600;
	xl = 270;
	yl = 125;
	xc = 3850;
	ymenuvir = 28;
	yvir = 720;
	entrou = false;
	hanvenceu = false;
	shuvenceu = false;
	cond_largada = false;
	player1_vitoria = false;
	player2_vitoria = false;

	//menu, cenario, sprites cenario, virada e largada.
	//
	gRecursos.carregarSpriteSheet("raio", "./dados/spritesheets/raio_novo_e_suporte.png", 1, 2);
	raio_novinho.setSpriteSheet("raio");
	gRecursos.carregarSpriteSheet("presents", "./dados/spritesheets/apresentacao_inicio.png", 1, 3);
	apresentacao_inicio.setSpriteSheet("presents");
	gRecursos.carregarSpriteSheet("intro", "./dados/spritesheets/menu_novo.png");
	intro.setSpriteSheet("intro");
	gRecursos.carregarSpriteSheet("opcaomenu", "./dados/spritesheets/flexa.png");
	opcaomenu.setSpriteSheet("opcaomenu");
	gRecursos.carregarSpriteSheet("fundo", "./dados/spritesheets/fundo.png");
	fundo.setSpriteSheet("fundo");
	gRecursos.carregarSpriteSheet("esteira", "./dados/spritesheets/esteira.png");
	esteira.setSpriteSheet("esteira");
	gRecursos.carregarSpriteSheet("hanlargada", "./dados/spritesheets/hansolo_largada.png");
	hanlargada.setSpriteSheet("hanlargada");
	gRecursos.carregarSpriteSheet("shubalargada", "./dados/spritesheets/shubaca_largada.png");
	shubalargada.setSpriteSheet("shubalargada");
	gRecursos.carregarSpriteSheet("largada", "./dados/spritesheets/placar_contagem_novo.png", 1, 3);
	largada.setSpriteSheet("largada");
	gRecursos.carregarSpriteSheet("largadago", "./dados/spritesheets/placar_contagem_goo_novo.png", 1, 2);
	largadago.setSpriteSheet("largadago");
	gRecursos.carregarSpriteSheet("chegada", "./dados/spritesheets/chegada.png");
	chegada.setSpriteSheet("chegada");
	gRecursos.carregarSpriteSheet("chegadahan", "./dados/spritesheets/placar_chegada_hansolo.png", 1, 10);
	placar_chegadahan.setSpriteSheet("chegadahan");
	gRecursos.carregarSpriteSheet("chegadashu", "./dados/spritesheets/placar_chegada_shubaca.png", 1, 10);
	placar_chegadashu.setSpriteSheet("chegadashu");
	gRecursos.carregarSpriteSheet("viradahan", "./dados/spritesheets/virada_han.png");
	viradahan.setSpriteSheet("viradahan");
	gRecursos.carregarSpriteSheet("viradashu", "./dados/spritesheets/virada_shu.png");
	viradashu.setSpriteSheet("viradashu");
	gRecursos.carregarSpriteSheet("menuvirada", "./dados/spritesheets/menu_virada.png");
	menuvirada.setSpriteSheet("menuvirada");
	gRecursos.carregarSpriteSheet("choque", "./dados/spritesheets/choque2.png", 1, 2);
	choque.setSpriteSheet("choque");
	gRecursos.carregarSpriteSheet("tutorial", "./dados/spritesheets/teclado_config1_novo.png");
	tutorial.setSpriteSheet("tutorial");
	gRecursos.carregarSpriteSheet("indicador", "./dados/spritesheets/indicador.png", 1, 2);
	indicador.setSpriteSheet("indicador");

	//musicas e sons
	//
	//musicamenu.carregar("./dados/sons/musicamenu.mp3");
	//musicafundo.carregar("./dados/sons/music_corrida6.MP3");
	//musicavitoria.carregar("./dados/sons/music_virada.mp3");
	gRecursos.carregarMusica("musicaMenu", "./dados/sons/musicamenu.mp3");
	gRecursos.carregarMusica("musicaFundo", "./dados/sons/musicamenu.mp3");
	gRecursos.carregarMusica("musicaVitoria", "./dados/sons/musicamenu.mp3");

	gRecursos.carregarAudio("eletrocutado", "./dados/sons/eletrocutado.wav");
	branco.setaudio("eletrocutado");
	shuba.setaudio("eletrocutado");


	//player 1 (han solo)
	//
	branco.inicializar(1, "branco", "./dados/spritesheets/hansolo_correndo.png", 1, 8);
	pular.inicializar(1, "pular", "./dados/spritesheets/hansolo_pulando.png", 1, 1);
	vencer.inicializar(1, "dancavitoria", "./dados/spritesheets/dancinha_hansolo2.png", 1, 12);

	//player 2 (chewbacca)
	//
	shuba.inicializar(2, "chubacca", "./dados/spritesheets/shubaca_comp.png", 1, 6);
	shubapular.inicializar(2, "chubaccapular", "./dados/spritesheets/chubaca_pulando.png", 1, 1);
	shuvencer.inicializar(2, "shuvencer", "./dados/spritesheets/dancinha_shu.png", 1, 12);

	//obstaculos e choque players
	//
	raio.inicializar(true, "raio");
	raio2.inicializar(false, "raio");

}

void Jogo::finalizar()
{
	gRecursos.descarregarTodasMusicas();
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while ((!gTeclado.soltou[TECLA_ESC]) && !gEventos.sair)
	{
		uniIniciarFrame();

		switch (status)
		{

		case apresentacao:

			//if (!musicamenu.estaTocando())
			//{
			//	musicamenu.tocar();
			//}
			if (!gMusica.estaTocando)		
				gMusica.tocar("musicaMenu", true);	

			apresentacao_inicio.desenhar(640, 360);
			apresentacao_inicio.avancarAnimacao();
			apresentacao_inicio.setVelocidadeAnimacao(.08);

			if (apresentacao_inicio.terminouAnimacao())
			{
				status = menu;
			}

			break;

		case menu:

			//if (!musicamenu.estaTocando())
			//{
			//	musicamenu.tocar();
			//}
			if (!gMusica.estaTocando)
				gMusica.tocar("musicaMenu", true);

			intro.desenhar(640, 360);
			opcaomenu.desenhar(520, yf);

			//seleção menu - para jogar
			//
			if (gTeclado.soltou[TECLA_ENTER] && yf == 600)
			{
				status = teclado_players;
			}

			//seleção menu - mudar seleção
			//
			if (gTeclado.soltou[TECLA_BAIXO] && yf == 600)
			{
				yf = 670;
				opcaomenu.desenhar(520, yf);
			}

			//seleção menu - mudar seleção
			//
			if (gTeclado.soltou[TECLA_CIMA] && yf == 670)
			{
				yf = 600;
				opcaomenu.desenhar(520, yf);
			}

			//seleção menu - sair do jogo
			//
			if (gTeclado.soltou[TECLA_ENTER] && yf == 670)
			{
				gEventos.sair = true;
			}

			break;

		case teclado_players:

			tutorial.desenhar(640, 360);

			if (gTeclado.soltou[TECLA_ENTER])
			{
				//musicamenu.parar();
				gMusica.parar();
				status = jogando;
			}

			break;

		case jogando:

			//inicio jogo com largada
			//
			if (!cond_largada)
			{
				esteira.desenhar(xe, 360);
				fundo.desenhar(xf, 360);
				hanlargada.desenhar(90, 560);
				largada.desenhar(xl, yl);
				shubalargada.desenhar(150, 460);
				largada.avancarAnimacao();
				largada.setVelocidadeAnimacao(.5);

				//termina animação de contagem ele da a largada
				//
				if (largada.terminouAnimacao())
				{
					cond_largada = true;
				}
			}

			//apos a largada roda apartir daqui o jogo
			//
			if (cond_largada)
			{

				//if (!musicafundo.estaTocando())
				//{
				//	musicafundo.tocar();
				//}
				if (!gMusica.estaTocando)
					gMusica.tocar("musicaFundo", true);


				//condição para esteira continua: inicio
				//
				if (xe <= -1280)
				{
					xe = 3840;
				}

				if (xe2 <= -1280)
				{
					xe2 = 3840;
				}

				xe--;
				xe2--;

				esteira.desenhar(xe, 360);
				esteira.desenhar(xe2, 360);
				//
				//condição para esteira continua: fim

				fundo.desenhar(xf, 360);

				if (branco.getX() < -5)
				{
					indicador.desenhar(80, 600);
					indicador.avancarAnimacao();
					indicador.setVelocidadeAnimacao(.9);
				}

				if (shuba.getX() < -5)
				{
					indicador.desenhar(80, 490);
					indicador.avancarAnimacao();
					indicador.setVelocidadeAnimacao(1);
				}

				//animação do placar após a largada (GO): inicio
				//
				largadago.desenhar(xl, yl);
				largadago.avancarAnimacao();
				largadago.setVelocidadeAnimacao(3);
				//
				//animação do placar após a largada (GO): fim

				//o placar da chegada é desenhado aqui e vem junto com o andamento do cenário fazendo-o aparecer na posição correta de forma suave
				//
				chegada.desenhar(xc, yl);

				//condição para ao passar do meio da tela o cenario mover junto
				//
				if (((branco.getX() > gJanela.getLargura() / 2) || (shuba.getX() > gJanela.getLargura() / 2)) && xf > -720)
				{
					xf -= 1.1;
					xe -= .5;
					xe2 -= .5;
					xl -= 1.1;
					xc -= 1.1;
				}

				shuba.desenhar();
				branco.desenhar();

				//aqui ele faz a colisao e desenha os obstaculos player 1 apenas se ainda n venceu ou se não está nos ultimos 50m
				//
				if (!hanvenceu)
				{
					raio.desenhar();
					raio.atualizar();

					//if (uniColisao(branco.getSprite(), branco.getX(), branco.getY(), 0,	raio.getSprite(), raio.getX(), raio.getY(), 0))
					//	branco.colidir();
					//if (uniTestarColisao(branco.getSprite(), branco.getX(), branco.getY(), raio.getSprite(), raio.getX(), raio.getY(), 0))
					//	branco.colidir();
				}

				//aqui ele faz a colisao e desenha os obstaculos player 2 apenas se ainda n venceu ou se não está nos ultimos 50m
				//
				if (!shuvenceu)
				{
					raio2.desenhar();
					raio2.atualizar();

					//if (uniColisao(shuba.getSprite(), shuba.getX(), shuba.getY(), 0,
					//	raio2.getSprite(), raio2.getX(), raio2.getY(), 0))
					//	shuba.colidir();
				}

				//definição para vitoria do player 1 e preparação para mudança de status
				//
				if ((branco.getX() + 210) > xc)
				{
					hanvenceu = true;

					placar_chegadahan.desenhar(1130, yl);
					placar_chegadahan.avancarAnimacao();
					placar_chegadahan.setVelocidadeAnimacao(.8);
					branco.vencedor_han();

					if ((placar_chegadahan.terminouAnimacao() && shuvenceu) || placar_chegadahan.terminouAnimacao())
					{
						status = menuContinuar;
						//musicafundo.parar();
						gMusica.parar();
						player1_vitoria = true;
					}
				}

				//definição para vitoria do player 2 e preparação para mudança de status
				//
				if ((shuba.getX() + 140) > xc)
				{
					shuvenceu = true;

					placar_chegadashu.desenhar(1130, yl);
					placar_chegadashu.avancarAnimacao();
					placar_chegadashu.setVelocidadeAnimacao(.8);
					shuba.vencedor_shu();

					if ((placar_chegadashu.terminouAnimacao() && hanvenceu) || placar_chegadashu.terminouAnimacao())
					{
						status = menuContinuar;
						//musicafundo.parar();
						gMusica.parar();
						player2_vitoria = true;
					}
				}
			}

			break;

		case menuContinuar:

			//if (!musicavitoria.estaTocando())
			//	musicavitoria.tocar();
			if (!gMusica.estaTocando)
				gMusica.tocar("musicaVitoria", true);
				

			//desenhar virada player1
			//
			if (player1_vitoria)
				viradahan.desenhar(640, yvir);

			//desenhar virada player2
			//
			if (player2_vitoria)
				viradashu.desenhar(640, yvir);

			//apresentação virada
			//
			if (yvir > 0)
				yvir -= .7;

			//menu pós jogado para definir se continua jogando ou sair do jogo
			//
			if (yvir <= 0)
			{
				menuvirada.desenhar(740, 45);
				opcaomenu.desenhar(600, ymenuvir);
			}

			//seleção menu pós jogo - para jogar novamente, aqui é reiniciado todos as classes e condições iniciais de jogo
			//
			if (gTeclado.soltou[TECLA_ENTER] && ymenuvir == 28)
			{
				status = jogando;
				//musicavitoria.parar();
				gMusica.parar();
				branco.reiniciar("branco", 1, 8, 90, 560, false);
				shuba.reiniciar("chubacca", 1, 6, 150, 460, false);
				raio.reiniciar(true, "raio", 1, 2, 1500, 585);
				raio2.reiniciar(false, "raio2", 1, 2, 1450, 485);
				reiniciar(2000, 270, 3850, 1280, 3840, 720, false, false, false, false, false, false);
			}

			//seleção menu pós jogo - mudar seleção
			//
			if (gTeclado.soltou[TECLA_BAIXO] && ymenuvir == 28)
			{
				ymenuvir = 70;
				opcaomenu.desenhar(500, ymenuvir);
			}

			//seleção menu pós jogo - mudar seleção
			//
			if (gTeclado.soltou[TECLA_CIMA] && ymenuvir == 70)
			{
				ymenuvir = 28;
				opcaomenu.desenhar(500, ymenuvir);
			}

			//seleção menu pós jogo - sair para o menu
			//
			if (gTeclado.soltou[TECLA_ENTER] && ymenuvir == 70)
			{
				status = menu;
				//musicavitoria.parar();
				gMusica.parar();
				branco.reiniciar("branco", 1, 8, 90, 560, false);
				shuba.reiniciar("chubacca", 1, 6, 150, 460, false);
				raio.reiniciar(true, "raio", 1, 2, 1500, 585);
				raio2.reiniciar(false, "raio2", 1, 2, 1450, 485);
				reiniciar(2000, 270, 3850, 1280, 3840, 720, false, false, false, false, false, false);
			}

			break;
		}

		uniTerminarFrame();
	}
}


//função para poder reiniciar a partida do zero
//
void Jogo::reiniciar(int posxfundo, int posxl, int posxc, int posxe, int posxe2, int posyvir,
	bool hanvenceu_rein, bool shuvenceu_rein, bool cond_largada_rein, bool virada_1, bool virada_2, bool sair_rein)
{
	//sair = sair_rein;
	gEventos.sair = sair_rein;
	player1_vitoria = virada_1;
	player2_vitoria = virada_2;
	xe = posxe;
	xe2 = posxe2;
	cond_largada = cond_largada_rein;
	yvir = posyvir;
	xf = posxfundo;
	xl = posxl;
	xc = posxc;
	hanvenceu = hanvenceu_rein;
	shuvenceu = shuvenceu_rein;
}
