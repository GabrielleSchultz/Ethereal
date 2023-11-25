#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Plataforma : public Obstaculo
		{
		private:
			float forca_normal;
		public:
			Plataforma(Math::Vector2Df posicao = Math::Vector2Df(0.f, 0.f), const char* texture = "Assets/Sprites/middle_ground_sprite.png", ID id = ID::plataforma);
			~Plataforma();
			void obstacular(Entidades::Personagens::Jogador* p);
			void update(float dt);
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& saida);
		};
	}

}