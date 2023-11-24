#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {
	namespace Obstaculos {
		class Obstaculo : public Entidade {
		protected:
			bool danoso;
		public:
			Obstaculo(Math::Vector2Df posicao = Math::Vector2Df(0.f,0.f), const char* texture = "", ID id = ID::vazio);
			~Obstaculo();
			virtual void obstacular(Personagens::Jogador* p) = 0;
			virtual void salvar(nlohmann::ordered_json& entrada) = 0;
			void update(float dt) = 0;
		};
	}
}
