#pragma once

#include "Inimigo.h"
#include "Projetil.h"

namespace Entidades {
	namespace Personagens {
		class Tristeza : public Inimigo {
		private:
			Listas::ListaEntidades projeteis;
			//Entidades::Projetil* projetil;
			int lancamento;
		public:
			Tristeza(int nv = 10, int mal = 0, const char* texturePath = "Assets/Sprites/sadness_teste.png", ID id = ID::inimigo_tristeza);
			~Tristeza();
			void executar();
			void danificar(Jogador* p);
			void salvar(std::ostringstream* entrada);
			void update(float dt);
			void lancar_projetil();
			void colidir();
			Listas::ListaEntidades* getProjeteis();
			//Projetil* getProjetil();
		};
	}
}