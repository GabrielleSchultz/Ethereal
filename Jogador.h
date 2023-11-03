#pragma once

#include "Personagem.h"

enum JogadorNum { Jogador1 = 1, Jogador2 = 2 };

namespace Entidades {
	namespace Personagens
	{
		class Jogador : public Personagem{

		private:
			int pontos;
			JogadorNum Player;
			bool Player1;
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
			Jogador(int nv = 0, const char* texturePath = "", JogadorNum player = Jogador1);
			~Jogador();
			void executar();
			void atualizar(float dt);
			void salvar();
			void operator++();
			bool isPlayer1();
		};
	}
}
