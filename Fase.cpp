#include <iostream>

#include "Fase.h"

namespace Fases
{

	Fase::Fase() :
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		pixi(nullptr), bity(nullptr),
		inimigos()
	{
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

	void Fases::Fase::criar_jogador(char type)
	{
		if (type == 'P')
		{
			//cria novo jogador 1
			//passa o jogador para o gerenciador grafico
			pixi = new Entidades::Personagens::Jogador(20, "Assets/Sprites/Pixi_cortado.png", Jogador1);
			pixi->setPosition(100, 450);
		}
		else if (type == 'B')
		{
			//cria novo jogador 2
			//passa o jogador para o gerenciador grafico
			bity = new Entidades::Personagens::Jogador(20, "Assets/Sprites/Bity_cortado.png", Jogador2);
			bity->setPosition(140, 450);
		}
		else
			std::cerr << "Erro ao criar jogador. Verificar arquivo de gera  o de mapa" << std::endl;
	}
}
