#include <iostream>

#include "Fase.h"

namespace Fases
{

	Fase::Fase() :
		Ente(),
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		inimigos(), obstaculos(), jogadores()
	{
		pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stage1_full_background.png");
		pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stars Small_1.png");
		pGerenciadorColisoes->setListaInimigos(&inimigos);
		pGerenciadorColisoes->setListaJogadores(&jogadores);
	}

	Fase::~Fase()
	{
	}

	void Fase::gerenciar_colisoes()
	{
		pGerenciadorColisoes->ColisaoJogInim();
		pGerenciadorColisoes->ColisaoProjInim();
		pGerenciadorColisoes->ColisaoProjJog();
	}

	void Fases::Fase::criar_jogador(char type)
	{
		Entidades::Personagens::Jogador* jogador = nullptr;
		
		if (type == 'P')
		{
			//cria novo jogador 1
			//passa o jogador para o gerenciador grafico
			jogador = new Entidades::Personagens::Jogador(50, "Assets/Sprites/Pixi_cortado.png", Jogador1);
			jogador->setPosition(100, 450);
			jogadores.incluir(jogador);
		}
		else if (type == 'B')
		{
			//cria novo jogador 2
			//passa o jogador para o gerenciador grafico
			jogador = new Entidades::Personagens::Jogador(50, "Assets/Sprites/Bity_cortado.png", Jogador2);
			jogador->setPosition(140, 450);
			jogadores.incluir(jogador);
		}
		else
			std::cerr << "Erro ao criar jogador. Verificar arquivo de gera o de mapa" << std::endl;
	}
}
