#include <iostream>
#include <fstream>

#include "Fase.h"
#include "json.h"

#include "Raiva.h"
#include "Tristeza.h"
#include "Vinganca.h"

namespace Fases
{
	Fase::Fase() :
		Ente(),
		pGerenciadorColisoes(Gerenciadores::Colisoes::getGerenciador_Colisoes()),
		num_fase(0), fim_de_fase(false), proxima_fase(false),
		inimigos(), obstaculos(), jogadores(), fila_delecao(),
		num_raivas(0), num_tristezas(0), num_vingancas(0)
	{
		pGerenciadorColisoes->setListaInimigos(&inimigos);
		pGerenciadorColisoes->setListaJogadores(&jogadores);
		pGerenciadorColisoes->setListaObstaculos(&obstaculos);
	}

	Fase::~Fase()
	{
		for (int i = 0; i < fila_delecao.size(); i++) {
			delete(fila_delecao[i]);
		}
		fila_delecao.clear();
		inimigos.clear();
		jogadores.clear();
		obstaculos.clear();
		pGerenciadorColisoes = nullptr;
	}

	void Fase::salvar(nlohmann::ordered_json& entrada)
	{
		nlohmann::ordered_json dados_fase;

		dados_fase["num_fase"] = num_fase;
		dados_fase["fim_de_fase"] = fim_de_fase;
		dados_fase["proxima_fase"] = proxima_fase;
		dados_fase["num_raivas"] = num_raivas;
		dados_fase["num_tristezas"] = num_tristezas;
		dados_fase["num_vingancas"] = num_vingancas;

		std::ofstream jsonOutput("../Ethereal/Data/fase_data.json");
		jsonOutput << std::setw(2) << dados_fase;

		jsonOutput.close();

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

	void Fase::carregar()
	{
		std::ifstream jsonInput("../Ethereal/Data/fase_data.json");
		if (!jsonInput)
			throw std::runtime_error("Error loading stage data!");
		nlohmann::ordered_json dados_fase = nlohmann::ordered_json::parse(jsonInput);
		num_fase = (dados_fase["num_fase"].template get<int>());
		fim_de_fase = (dados_fase["fim_de_fase"].template get<bool>());
		proxima_fase = (dados_fase["proxima_fase"].template get<bool>());
		num_raivas = (dados_fase["num_raivas"].template get<int>());
		num_tristezas = (dados_fase["num_tristezas"].template get<int>());
		num_vingancas = (dados_fase["num_vingancas"].template get<int>());

		jsonInput.close();

		criar_inimigos_carregados();

		carregarJogadores();
		carregarInimigos();
		carregarObstaculos();
	}

	void Fase::criar_inimigos_carregados()
	{
		Entidades::Personagens::Raiva* raivinha = nullptr;
		for (int i = 0; i < num_raivas; i++) {
			raivinha = new Entidades::Personagens::Raiva();
			if (raivinha)
			{
				inimigos.incluir(raivinha);
			}
		}

		Entidades::Personagens::Tristeza* sadness = nullptr;
		for (int i = 0; i < num_tristezas; i++) {
			sadness = new Entidades::Personagens::Tristeza();
			if (sadness)
			{
				inimigos.incluir(sadness);
			}
		}

		Entidades::Personagens::Vinganca* chefao = nullptr;
		for (int i = 0; i < num_vingancas; i++) {
			chefao = new Entidades::Personagens::Vinganca(25 * i + 30, 25 * i + 25);
			inimigos.incluir(chefao);
		}
	}

	void Fase::carregarJogadores()
	{
		std::ifstream jsonInput("../Ethereal/Data/jogadores_data.json");
		if (!jsonInput)
			throw std::runtime_error("Error loading stage data!");
		nlohmann::ordered_json dados_jogadores = nlohmann::ordered_json::parse(jsonInput);

		jogadores.carregar(dados_jogadores);

		jsonInput.close();
	}

	void Fase::carregarInimigos()
	{
		std::ifstream jsonInput("../Ethereal/Data/inimigos_data.json");
		if (!jsonInput)
			throw std::runtime_error("Error loading stage data!");
		nlohmann::ordered_json dados_inimigos = nlohmann::ordered_json::parse(jsonInput);

		jogadores.carregar(dados_inimigos);

		jsonInput.close();
	}

	void Fase::carregarObstaculos()
	{
		std::ifstream jsonInput("../Ethereal/Data/obstaculos_data.json");
		nlohmann::ordered_json dados_obstaculos = nlohmann::ordered_json::parse(jsonInput);

		jogadores.carregar(dados_obstaculos);

		jsonInput.close();
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
			jogador = new Entidades::Personagens::Jogador(50, "Assets/Sprites/Pixi_cortado.png", Jogador1);
			jogador->setPosition(posicao);
			jogadores.incluir(jogador);
		}
		else if (type == 'B')
		{
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
					fila_delecao.push_back(aux);
				}
				it.operator++(); i++;
			}
		}
		else if (lista->getTamanho() == 0) {
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
