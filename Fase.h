#pragma once

#include "Ente.h"
#include <string>

namespace Fases {

	class Fase: public Ente {
	protected:

	public:
		Fase();
		~Fase();
		virtual void executar() = 0;
		void gerenciar_colisoes();
		void criar_jogador(char type);
		virtual void criar_inimigos() = 0;
		virtual void criar_obstaculos() = 0;
		virtual void criar_cenario(std::string file_path) = 0;
	};

}