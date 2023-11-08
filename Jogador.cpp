#include "Jogador.h"

int Entidades::Personagens::Jogador::numJogadores(0);
int Entidades::Personagens::Jogador::pontos(0);

namespace Entidades {

	namespace Personagens {
        Jogador::Jogador(int nv, const char* texturePath, JogadorNum player, ID id) :
			Personagem(nv, texturePath, id),
			Player1(true),
			isGrounded(false),
			isJumping(false),
			Player(player),
			jumpPressedRemember(0.f),
			groundedRemember(0.f),
			groundedRememberTimer(0.2f),
			jumpPressedRememberTimer(0.2f),
			gravityCataliser(0.5f)
		{
			pControles = new Controle::ControleJogador();
			numJogadores++;
			inicializa();
        }

        Jogador::~Jogador()
		{
		}

		void Jogador::inicializa()
		{
			pControles->setJogador(this);

			if (Player == 2)
			{
				Player1 = false;
				pControles->setKeyCommands("up", "right", "left", "down");
			}
		} 

		void Jogador::update(float dt)
		{
			mover(dt);
			desenhar();
		}

		void Jogador::mover(float dt)
		{
			float velocidadeX = fabs(currentVelocity.x);

			if (velocidadeX < max_vel)
				currentVelocity.x += acceleration * direction.x * dt;

			//atrito
			if (currentVelocity.x > 0.f)
			{
				currentVelocity.x -= atrito * dt;
				if (currentVelocity.x < 0.f)
					currentVelocity.x = 0.f;
			}
			else if (currentVelocity.x < 0.f)
			{
				currentVelocity.x += atrito * dt;
				if (currentVelocity.x > 0.f)
					currentVelocity.x = 0.f;
			}

			setPosition(position.x + (currentVelocity.x * dt), position.y);
		}

		void Jogador::salvar(std::ostringstream* entrada)
		{
		}

		void Jogador::operator++()
		{
			pontos++;
		}
		bool Jogador::isPlayer1()
		{
			return Player1;
		}
		int Jogador::getNumJogadores()
		{
			return numJogadores;
		}
		void Jogador::atacar()
		{
		}
	}
}