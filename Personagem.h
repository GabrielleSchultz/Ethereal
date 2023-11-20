#pragma once
#include "Entidade.h"
#include "Entidade_Dinamica.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade, public Tipo::Dinamica {
		protected:
			int num_vidas;
			bool vivo;

		public:
			Personagem(int nv = 0, const char* texturePath = "", ID id = ID::vazio);
			~Personagem();
			bool getVivo();
			int getNumVidas() const;
			void setNumVidas(const int nv);
			virtual void colidir(Entidades::Entidade* e) = 0;
			virtual void update(float dt = 0) = 0;
			virtual void salvar(std::ostringstream* entrada) = 0;
		};
	}
}