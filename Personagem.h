#pragma once
#include "Entidade.h"
#include "DynamicBody.h" //include utils.h

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade, public DynamicBody {
		protected:
			int num_vidas;
			bool vivo;

		public:
			Personagem(int nv = 0, const char* texturePath = "");
			~Personagem();
			bool getVivo();
			virtual void update(float dt = 0) = 0;
			virtual void executar() = 0;
			virtual void salvar() = 0;
		};
	}
}