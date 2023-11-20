#pragma once

#include "Ente.h"
#include "Estado.h"
#include "ListaEntidades.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include <string>

namespace Fases {

	class Fase : public Ente, public Estados::Estado {
	protected:
		Gerenciadores::Colisoes* pGerenciadorColisoes;
		Listas::ListaEntidades inimigos;
		Listas::ListaEntidades obstaculos;
		Listas::ListaEntidades jogadores;

	public:
		Fase();
		~Fase();
		virtual void executar(float dt) = 0;
		virtual void desenhar() = 0;
		virtual void salvar(std::ostringstream* entrada) = 0;
		void gerenciar_colisoes();
		void criar_jogador(char type, Math::Vector2Df pos);
		virtual void criar_inimigos() = 0;
		virtual void criar_obstaculos() = 0;
		virtual void criar_cenario(std::string file_path) = 0;
		//virtual void criar_fundo(std::string file_path) = 0;
	};

}