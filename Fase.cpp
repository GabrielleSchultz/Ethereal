#include <iostream>

//abstract builder

#include "Fase.h"

namespace Fases
{

	Fase::Fase() :
		Ente(),
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		pixi(nullptr), bity(nullptr),
		inimigos(), obstaculos()
	{

		pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stage1_full_background.png");
		pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stars Small_1.png");
	}

	Fase::~Fase()
	{
	}

	void Fase::gerenciar_colisoes()
	{
		pGerenciadorColisoes->setListaInimigos(&inimigos);
		pGerenciadorColisoes->ColisaoJogInim(pixi);
		if (bity)
			pGerenciadorColisoes->ColisaoJogInim(bity);
	}

	void Fases::Fase::criar_jogador(char type, Math::Vector2Df pos)
	{
		if (type == 'P')
		{
			//cria novo jogador 1
			//passa o jogador para o gerenciador grafico
			pixi = new Entidades::Personagens::Jogador(20, "Assets/Sprites/Pixi_cortado.png", Jogador1);
			pixi->setPosition(pos.x, pos.y);
		}
		else if (type == 'B')
		{
			//cria novo jogador 2
			//passa o jogador para o gerenciador grafico
			bity = new Entidades::Personagens::Jogador(20, "Assets/Sprites/Bity_cortado.png", Jogador2);
			bity->setPosition(pos.x, pos.y);
		}
		else
			std::cerr << "Erro ao criar jogador. Verificar arquivo de gera o de mapa" << std::endl;
	}
}
