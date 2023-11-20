#pragma once
#include "Fase.h"
#include "Projetil.h"

namespace Fases {
	class Primeira_Fase : public Fase
	{
	private:

	public:
		Primeira_Fase();
		~Primeira_Fase();
		void executar(float dt);
		void salvar(std::ostringstream* entrada);
		void criar_inimigos();
		void criar_obstaculos();
		void criar_cenario(std::string file_path);
		void criar_fundo(std::string file_path);
	};
}