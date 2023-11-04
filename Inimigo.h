#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		protected:
			int nivel_maldade;
		public:
			Inimigo(int nv  = 0, int mal = 0, const char* texturePath = "", ID id = ID::vazio);
			~Inimigo();
			virtual void danificar(Jogador* p) = 0;
			virtual void executar() = 0;
			virtual void salvar() = 0;
			virtual void update(float dt = 0) = 0;
		};
	}
}