#include "Projetil.h"

namespace Entidades
{
	Projetil::Projetil(const char* texturePath, ID id) :
	Entidade_Dinamica(texturePath, id),
	velocidade(0)
	{
	}

	Projetil::~Projetil() {

	}

	void Projetil::setDirection(Math::Vector2Df posA, Math::Vector2Df posB)
	{
		direction = posB - posA;
	}

	void Projetil::executar() {

	}

	void Projetil::salvar() {

	}
}
