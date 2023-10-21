#pragma once
#include "Entidade.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade {
		protected:
			int num_vidas;
			bool vivo;

		public:
			Personagem();
			~Personagem();
			bool getVivo();
			virtual void executar() = 0;
			virtual void salvar() = 0;
		};
	}

}