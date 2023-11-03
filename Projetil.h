#pragma once
#include "Entidade.h"
#include "Entidade_Dinamica.h"

namespace Entidades {

	class Projetil : Entidade_Dinamica {
	
	private:
		int velocidade;

	public:
		Projetil(const char* texturePath, ID id = ID::projetil);
		~Projetil();
		void setDirection(Math::Vector2Df posA, Math::Vector2Df posB);
		void executar();
		void salvar();
	};

}
