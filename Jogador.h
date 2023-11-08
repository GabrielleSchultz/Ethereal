#pragma once

#include "Personagem.h"
#include "ControleJogador.h"

namespace Gerenciadores
{
	class Input;
}

enum JogadorNum { Jogador1 = 1, Jogador2 = 2 };

namespace Entidades {
	namespace Personagens
	{
		class Jogador : public Personagem{

		private:
			static int pontos;
			const float gravityCataliser;
			Controle::ControleJogador* pControles;

			//checagem de movimento
			bool isGrounded;
			bool isJumping;
			//remembers de movimento
			float jumpPressedRemember;
			float groundedRemember;
			//timers
			const float groundedRememberTimer;
			const float jumpPressedRememberTimer;

			//multiplayer
			JogadorNum Player;
			bool Player1;
			static int numJogadores;

		public:
			Jogador(int nv = 0, const char* texturePath = "", JogadorNum player = Jogador1, ID id = ID::jogador);
			~Jogador();
			void inicializa();
			void update(float dt);
			void mover(float dt);
			void salvar(std::ostringstream* entrada);
			void operator++();
			bool isPlayer1();
			static int getNumJogadores();
		};
	}
}
