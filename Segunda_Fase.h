#pragma once
#include "Fase.h"
#include "Projetil.h"

namespace Entidades {
	namespace Personagens {
		class Vinganca;
	}
}

namespace Fases {
	class Segunda_Fase : public Fase
	{
	private:
		Entidades::Personagens::Vinganca* boss;
		int boss_ativo;
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