#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Raiva : public Inimigo {
		private:
			float raio;
			float agilidade;
		public:
			Raiva(int nv = 10, int mal = 0, const char* texturePath = "Assets/Sprites/anger_teste.png", ID id = ID::inimigo_raiva);
			~Raiva();
			void executar();
			void salvar(std::ostringstream* entrada);
			void update(float dt);
			void colidir();
			void danificar(Jogador* p);
			void perseguir(Jogador* p);
		};
	}
}