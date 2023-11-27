#pragma once
#include "Fase.h"
#include "Projetil.h"
#include <vector>

namespace Fases {
	class Ressonancia : public Fase
	{
	private:
		const int max_raiva;
		const int max_tristeza;

	public:
		Ressonancia();
		~Ressonancia();
		void executar(float dt);
		void salvar(std::ostringstream* entrada);
		void criar_inimigos();
		void criar_obstaculos();
		void criar_cenario(std::string file_path);
	};
}