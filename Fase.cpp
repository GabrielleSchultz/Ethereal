#include <iostream>

#include "Fase.h"

namespace Fases
{

	Fase::Fase() :
		Ente(),
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		inimigos(), obstaculos(), jogadores(), mortos()
	{
		pGerenciadorColisoes->setListaInimigos(&inimigos);
		pGerenciadorColisoes->setListaJogadores(&jogadores);
		pGerenciadorColisoes->setListaObstaculos(&obstaculos);
	}

	Fase::~Fase()
	{
		for (int i = 0; i < mortos.size(); i++) {
			delete(mortos[i]);
		}
		mortos.clear();
		inimigos.clear();
		jogadores.clear();
		obstaculos.clear();
	}

	void Fase::gerenciar_colisoes()
	{
		pGerenciadorColisoes->ColisaoJogInim();
		pGerenciadorColisoes->ColisaoProjInim();
		pGerenciadorColisoes->ColisaoProjJog();
		pGerenciadorColisoes->ColisaoObs();
	}

	void Fases::Fase::criar_jogador(char type, Math::Vector2Df posicao)
	{
		Entidades::Personagens::Jogador* jogador = nullptr;

		if (type == 'P')
		{
			//cria novo jogador 1
			//passa o jogador para o gerenciador grafico
			jogador = new Entidades::Personagens::Jogador(50, "Assets/Sprites/Pixi_cortado.png", Jogador1);
			jogador->setPosition(posicao);
			jogadores.incluir(jogador);
		}
		else if (type == 'B')
		{
			//cria novo jogador 2
			//passa o jogador para o gerenciador grafico
			jogador = new Entidades::Personagens::Jogador(50, "Assets/Sprites/Bity_cortado.png", Jogador2);
			jogador->setPosition(posicao);
			jogadores.incluir(jogador);
		}
		else
			std::cerr << "Erro ao criar jogador. Verificar arquivo de gera o de mapa" << std::endl;
	}
	void Fase::remover_sem_vida(Listas::ListaEntidades* lista)
	{
		if(lista->getTamanho() > 0){
			Listas::Lista<Entidades::Entidade>::Iterador it = lista->get_primeiro();
			Entidades::Entidade* aux = it.operator*();
			int i = 0;
			
			while (i < lista->getTamanho()) {
				aux = it.operator*(); 
				if (!static_cast<Entidades::Personagens::Personagem*>(aux)->getVivo()) {
					lista->remover(aux);
					mortos.push_back(aux);
				}	
				it.operator++(); i++;
			}
		}
	}
}
