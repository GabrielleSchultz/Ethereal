#pragma once

#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include <string>
#include <vector>

namespace Fases {

	class Fase : public Ente {
	protected:
		int num_fase;
		bool fim_de_fase;
		bool proxima_fase;
		Gerenciadores::Colisoes* pGerenciadorColisoes;
		Listas::ListaEntidades inimigos;
		Listas::ListaEntidades obstaculos;
		Listas::ListaEntidades jogadores;
		std::vector<Entidades::Entidade*> fila_delecao;
		int num_raivas;
		int num_tristezas;
		int num_vingancas;

	public:
		Fase();
		~Fase();
		virtual void executar(float dt) = 0;
		
		virtual void salvar(nlohmann::ordered_json& entrada);
		virtual void salvarJogadores();
		virtual void salvarInimigos();
		virtual void salvarObstaculos();
		virtual void carregar();
		void criar_inimigos_carregados();
		virtual void carregarJogadores();
		virtual void carregarInimigos();
		virtual void carregarObstaculos();
		
		void gerenciar_colisoes();
		int getPontuacaoJogadores() const;
		void criar_jogador(char type, Math::Vector2Df posicao);
		void remover_sem_vida(Listas::ListaEntidades* lista);
		bool getfim_de_fase();
		bool getproxima_fase();
		virtual void criar_inimigos() = 0;
		virtual void criar_obstaculos() = 0;
		virtual void criar_cenario(std::string file_path) = 0;
	};

}