#include "Jogador.h"

namespace Entidades {

	namespace Personagens {
        Jogador::Jogador(int nv, const char* texturePath, JogadorNum player) :
			Personagem(nv, texturePath),
			pontos(0),
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
				if (Player == 2)
					Player1 = false;

        }
        Jogador::~Jogador()
		{
		}

		void Jogador::executar()
		{
		}

		void Jogador::atualizar(float dt)
		{
            direction = 0.f;

			//aceleração
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                direction.x = -1.f;
                if (currentVelocity.x > -max_vel)
                    currentVelocity.x += acceleration * direction.x * dt;
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                direction.x = 1.f;
                if (currentVelocity.x < max_vel)
                    currentVelocity.x += acceleration * direction.x * dt;
            }

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

		}

		void Jogador::salvar()
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
	}
}