#pragma once
#include "Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			bool danoso;
		public:
			Obstaculo();
			~Obstaculo();
			virtual void obstacular(Jogador* p) = 0;
			virtual void executar() = 0;
			virtual void salvar() = 0;
		};
	}
}