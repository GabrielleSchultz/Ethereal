#pragma once
#include "Obstaculo.h"

namespace Entidades{
	namespace Obstaculos
	{
		class Espinhos : public Obstaculo
		{
		private:
			int dano;
		public:
			Espinhos(Math::Vector2Df posicao = Math::Vector2Df(0.f, 0.f), const char* texture = "Assets/Sprites/spike_cortado.png", ID id = ID::espinhos);
			~Espinhos();
			void obstacular(Entidades::Personagens::Jogador* p);
			void espetar(Entidades::Personagens::Jogador* p);
			void update(float dt);
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& saida);
		};

	}
}