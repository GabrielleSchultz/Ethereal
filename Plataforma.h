#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Plataforma : public Obstaculo
		{
		private:
			float forca_normal;
		public:
			Plataforma(Math::Vector2Df posicao = Math::Vector2Df(0.f, 0.f), const char* texture = "", ID id = ID::plataforma);
			~Plataforma();
			void obstacular(Entidades::Personagens::Jogador* p);
			void executar();
			void salvar();
		};
	}

}