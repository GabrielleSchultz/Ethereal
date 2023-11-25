#pragma once

#include "Personagem.h"
#include "ControleJogador.h"
#include "Projetil.h"
#include "ListaEntidades.h"
#include <vector>

namespace Gerenciadores
{
	class Input;
}

enum JogadorNum { Jogador1 = 1, Jogador2 = 2 };

namespace Entidades {
	namespace Personagens
	{
		class Jogador : public Personagem {

		private:
			static int pontos;
			const float gravityCataliser;
			float gravityScale;
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
			static int numJogadores;

			Listas::ListaEntidades projeteis;
			std::vector<Entidades::Entidade*> projeteis_lancados;
			int lancamento;

			bool facingRight;

		public:
			Jogador(int nv = 50, const char* texturePath = "", JogadorNum player = Jogador1, ID id = ID::jogador);
			~Jogador();
			void inicializa();
			void update(float dt);
			void mover(float dt);
			void salvar(std::ostringstream* entrada);
			void operator++(int p);
			static const int getPontos();
			static int getNumJogadores();
			void colidir(Entidades::Entidade* e);
			void atacar();
			void pular();
			void remover_projeteis();
			bool getFacingRight() const;
			void setFacingRight(const bool b);
			bool getIsGrounded();
			Listas::ListaEntidades* getProjeteis();
		};
	}
}