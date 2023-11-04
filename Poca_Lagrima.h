#pragma once
#include "Obstaculo.h"

namespace Entidades{
	namespace Obstaculos
	{
		class Poca_Lagrimas : public Obstaculo
		{
		private:
			float slowdown;
		public:
			Poca_Lagrimas(Math::Vector2Df posicao = Math::Vector2Df(0.f, 0.f), const char* texture = "", ID id = ID::poca_lagrima);
			~Poca_Lagrimas();
			void obstacular(Entidades::Personagens::Jogador* p);
			void executar();
			void salvar();
		};
	}
}