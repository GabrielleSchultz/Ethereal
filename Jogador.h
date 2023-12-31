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
			static unsigned int pontos;
			const float gravityCataliser;
			float gravityScale;
			Controle::ControleJogador* pControles;

			//checagem de movimento
			bool isGrounded;
			bool isJumping;
			const float jumpSpeed;

			//multiplayer
			JogadorNum Player;
			static int numJogadores;

			//projeteis
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
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& saida);
			void operator++(int p);
			static unsigned int getPontos();
			static int getNumJogadores();
			void colidir(Entidades::Entidade* e);
			void atacar();
			void pular();
			void aplicarFisica(float dt);
			void remover_projeteis();
			bool getFacingRight() const;
			void setFacingRight(const bool b);
			bool getIsGrounded();
			Listas::ListaEntidades* getProjeteis();
			static void zeraPontos();
		};
	}
}