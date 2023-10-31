#pragma once

#include "Personagem.h"

namespace Entidades {
	namespace Personagens
	{
		class Jogador : public Personagem{

		private:
			//static int pontos;

		public:
			Jogador(int nv = 0, const char* texturePath = "");
			~Jogador();
			void executar();
			void atualizar(float dt);
			void salvar();
			void carregar();
			void operator++();
		};

//		int Jogador::pontos(0);
	}
}