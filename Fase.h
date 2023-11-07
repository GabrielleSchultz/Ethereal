#pragma once

#include "Ente.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include <string>

namespace Fases {

	class Fase: public Ente {
	protected:
		Gerenciadores::Colisoes* pGerenciadorColisoes;
		Entidades::Personagens::Jogador* pixi;
		Entidades::Personagens::Jogador* bity;
		Listas::ListaEntidades inimigos;

	public:
		Fase();
		~Fase();
		virtual void executar(float dt) = 0;
		virtual void desenhar() = 0;
		virtual void salvar(std::ostringstream* entrada) = 0;
		void gerenciar_colisoes();
		void criar_jogador(char type);
		virtual void criar_inimigos() = 0;
		virtual void criar_obstaculos() = 0;
		virtual void criar_cenario(std::string file_path) = 0;
	};

}