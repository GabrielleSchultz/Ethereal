#include <iostream>
#include <fstream>

#include "Fase.h"
#include "json.h"

namespace Fases
{
	Fase::Fase() :
		Ente(),
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		inimigos(), obstaculos(), jogadores()
	{
		pGerenciadorColisoes->setListaInimigos(&inimigos);
		pGerenciadorColisoes->setListaJogadores(&jogadores);
		pGerenciadorColisoes->setListaObstaculos(&obstaculos);
	}

	Fase::~Fase()
	{
	}

	void Fase::salvar()
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
}
