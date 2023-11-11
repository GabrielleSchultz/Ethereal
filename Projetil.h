#pragma once
#include "Entidade.h"
#include "Entidade_Dinamica.h"

namespace Entidades {

	class Projetil : public Entidade, public Tipo::Dinamica {

	private:
		int velocidade;
		int dano;
		Entidade* atirador;
		bool colidiu;

	public:
		Projetil(const char* texturePath = "", int d = 0, ID id = ID::projetil);
		~Projetil();
		void setAtirador(Entidade* a);
		bool getColidiu() const;
		void colidir();
		void update(float dt);
		void salvar(std::ostringstream* entrada);
	};

}