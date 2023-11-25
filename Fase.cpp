#include <iostream>
#include <fstream>

#include "Fase.h"
#include "json.h"

namespace Fases
{
	Fase::Fase() :
		Ente(),
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		fim_de_fase(false), proxima_fase(false),
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

	void Fase::salvar(nlohmann::ordered_json& entrada)
	{
		salvarJogadores();
		salvarInimigos();
		salvarObstaculos();
	}

	void Fase::salvarJogadores()
	{
		//cria o objeto json para salvar jogadores
		nlohmann::ordered_json dados_jogadores;
		//salva cada um dos jogadores da lista e da um push_back em dados_jogadores
		jogadores.salvar(dados_jogadores);

		//formata e grava no arquivo de saida
		std::ofstream jsonOutput("../Ethereal/Data/jogadores_data.json");
		jsonOutput << std::setw(2) << dados_jogadores;

		jsonOutput.close();
	}

	void Fase::salvarInimigos()
	{
		//cria o objeto json para salvar jogadores
		nlohmann::ordered_json dados_inimigos;
		//salva cada um dos jogadores da lista e da um push_back em dados_jogadores
		inimigos.salvar(dados_inimigos);

		//formata e grava no arquivo de saida
		std::ofstream jsonOutput("../Ethereal/Data/inimigos_data.json");
		jsonOutput << std::setw(2) << dados_inimigos;

		jsonOutput.close();
	}

	void Fase::salvarObstaculos()
	{
		//cria o objeto json para salvar jogadores
		nlohmann::ordered_json dados_obstaculos;
		//salva cada um dos jogadores da lista e da um push_back em dados_jogadores
		jogadores.salvar(dados_obstaculos);

		//formata e grava no arquivo de saida
		std::ofstream jsonOutput("../Ethereal/Data/obstaculos_data.json");
		jsonOutput << std::setw(2) << dados_obstaculos;

		jsonOutput.close();
	}

	void Fase::gerenciar_colisoes()
	{
		pGerenciadorColisoes->ColisaoJogInim();
		pGerenciadorColisoes->ColisaoProjInim();
		pGerenciadorColisoes->ColisaoProjJog();
		pGerenciadorColisoes->ColisaoObs();
	}

	int Fase::getPontuacaoJogadores() const
	{
		return Entidades::Personagens::Jogador::getPontos();
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
		if (lista->getTamanho() > 0) {
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
		else if (lista->getTamanho() == 0){
			fim_de_fase = true;
		}
	}
	bool Fase::getfim_de_fase()
	{
		return fim_de_fase;
	}
	bool Fase::getproxima_fase()
	{
		return proxima_fase;
	}
}
