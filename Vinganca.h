#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Vinganca : public Inimigo {
		private:
		public:
			Vinganca(int nv = 0, int mal = 0, const char* texturePath = "Assets/Sprites/Bytie_static_sprite.png", ID id = ID::boss);
			~Vinganca();
			void executar();
			void danificar(Jogador* p);
			void salvar();
			void update(float dt);
		};
	}
}