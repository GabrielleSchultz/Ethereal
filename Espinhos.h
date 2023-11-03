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
			Espinhos(Math::Vector2Df posicao = Math::Vector2Df(0.f, 0.f), const char* texture = "", ID id = ID::espinhos);
			~Espinhos();
			void obstacular(Entidades::Personagens::Jogador* p);
			void executar();
			void salvar();
		};

	}
}