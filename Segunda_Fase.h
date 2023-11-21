#pragma once
#include "Fase.h"
#include "Projetil.h"

namespace Fases {
	class Segunda_Fase : public Fase
	{
	private:
		// vetor de Vingança
	public:
		Segunda_Fase();
		~Segunda_Fase();
		void executar(float dt);
		void salvar(std::ostringstream* entrada);
		void criar_inimigos();
		void criar_obstaculos();
		void criar_cenario(std::string file_path);
	};
}