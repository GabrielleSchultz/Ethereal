#pragma once
#include "Entidade.h"
#include "Entidade_Dinamica.h"

namespace Entidades {

	class Projetil : public Entidade, public Tipo::Dinamica {
	
	private:
		int velocidade;
		int dano;

	public:
		Projetil(const char* texturePath, ID id = ID::projetil);
		~Projetil();
		void setDirection(Math::Vector2Df posA, Math::Vector2Df posB);
		void executar();
		void salvar();
	};

}
