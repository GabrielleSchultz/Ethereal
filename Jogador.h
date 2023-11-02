#pragma once

#include "Personagem.h"

namespace Entidades {
	namespace Personagens
	{
		class Jogador : public Personagem{

		private:
			int pontos;
			const float gravityCataliser;
			//checagem de movimento
			bool isGrounded;
			bool isJumping;
			//remembers de movimento
			float jumpPressedRemember;
			float groundedRemember;
			//timers
			const float groundedRememberTimer;
			const float jumpPressedRememberTimer;

		public:
			Jogador(int nv = 0, const char* texturePath = "");
			~Jogador();
			void executar();
			void atualizar(float dt);
			void salvar();
			void operator++();
		};
	}
}
