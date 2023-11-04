#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Raiva : public Inimigo {
		private:
			float raio;
			float agilidade;
		public:
			Raiva(int nv = 0, int mal = 0, const char* texturePath = "Assets/Sprites/anger_teste.png", ID id = ID::inimigo_raiva);
			~Raiva();
			void executar();
			void danificar(Jogador* p);
			void salvar();
			void update(float dt);
		};
	}
}