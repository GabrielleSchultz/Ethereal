#pragma once
#include "Personagem.h"

namespace Entidades {

	class Projetil : public Entidade, public Tipo::Dinamica {

	private:
		int velocidade;
		int dano;
		Entidade* atirador;
		bool colidiu;

	public:
		Projetil(const char* texturePath = "", int d = 0, int v = 5, ID id = ID::projetil);
		~Projetil();
		void setAtirador(Entidade* a);
		bool getColidiu() const;
		void colidir();
		void danificar(Entidades::Personagens::Personagem* p);
		void update(float dt);
		void salvar(std::ostringstream* entrada);
	};

}