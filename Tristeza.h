#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Tristeza : public Inimigo {
		private:
			// objeto ou lista de Projetil talvez (?) 
		public:
			Tristeza(int nv = 0, int mal = 0, const char* texturePath = "Assets/Sprites/sadness_teste.png", ID id = ID::inimigo_tristeza);
			~Tristeza();
			void executar();
			void danificar(Jogador* p);
			void salvar();
			void update(float dt);
		};
	}
}