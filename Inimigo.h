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
			virtual void colidir(Entidades::Entidade* e) = 0;
			void salvarInimigo(nlohmann::ordered_json& entrada);
			virtual void salvar(nlohmann::ordered_json& entrada) = 0;
			virtual void update(float dt = 0) = 0;
		};
	}
}