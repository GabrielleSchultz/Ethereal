#include "Projetil.h"

namespace Entidades
{
	Projetil::Projetil() : Entidade(), velocidade(0) {
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
