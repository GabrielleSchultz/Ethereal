#pragma once
#include "Entidade_Dinamica.h"

namespace Entidades {

	class Projetil : public Entidade_Dinamica {
	
	private:
		int velocidade;
		int dano;
		Entidade* atirador;
		bool colidiu;

	public:
		Projetil(const char* texturePath, int d, ID id = ID::projetil);
		~Projetil();
		void setAtirador(Entidade* a);
		bool getColidiu() const;
		void colidir();
		void update(float dt);
		void salvar(std::ostringstream* entrada);
	};

}
