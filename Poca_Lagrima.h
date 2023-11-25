#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos
	{
		class Poca_Lagrimas : public Obstaculo
		{
		private:
			float coeficiente_aceleracao;
		public:
			Poca_Lagrimas(Math::Vector2Df posicao = Math::Vector2Df(0.f, 0.f), const char* texture = "Assets/Sprites/tear_pond.png", ID id = ID::poca_lagrima);
			~Poca_Lagrimas();
			void obstacular(Entidades::Personagens::Jogador* p);
			void update(float dt);
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& saida);

		};
	}
}