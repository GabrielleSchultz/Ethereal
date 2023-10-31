#include "Jogador.h"

namespace Entidades {

	namespace Personagens {

		Jogador::Jogador(int nv, const char* texturePath) :
		Personagem(nv, texturePath),
		pontos (0),
		isGrounded(false),
		isJumping(false),
		jumpPressedRemember(0.f),
		groundedRemember (0.f),
		groundedRememberTimer(0.2f),
		jumpPressedRememberTimer(0.2f)
		{
		}

		Jogador::~Jogador()
		{
		}

		void Jogador::executar()
		{
		}

		void Jogador::atualizar(float dt)
		{

		}

		void Jogador::salvar()
		{
		}

		void Jogador::carregar()
		{
		}

		void Jogador::operator++()
		{
			pontos++;
		}
	}
}