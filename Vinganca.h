#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Vinganca : public Inimigo {
		private:
		public:
			Vinganca(int nv = 200, int mal = 100, const char* texturePath = "Assets/Sprites/Bytie_static_sprite.png", ID id = ID::boss);
			~Vinganca();
			void executar();
			void danificar(Jogador* p);
			void colidir(Entidades::Entidade* e);
			void salvar(std::ostringstream* entrada);
			void update(float dt);
		};
	}
}