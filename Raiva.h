#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Raiva : public Inimigo {
		private:
			float raio;
			float agilidade;
		public:
			Raiva(int nv = 10, int mal = 1, const char* texturePath = "Assets/Sprites/anger_teste.png", ID id = ID::inimigo_raiva);
			~Raiva();
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& saida);
			void update(float dt);
			void mover(float dt);
			void colidir(Entidades::Entidade* e);
			void danificar(Jogador* p);
			void perseguir(Jogador* p);
		};
	}
}