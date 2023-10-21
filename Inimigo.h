#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem {
		protected:
			int nivel_maldade;
		public:
			Inimigo(int nv, int mal);
			~Inimigo();
			virtual void danificar(Jogador* p) = 0;
			virtual void executar() = 0;
			virtual void salvar() = 0;
		};
	}
}