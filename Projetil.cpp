#include "Projetil.h"

namespace Entidades
{
	Projetil::Projetil(const char* texturePath, int d, int v, ID id) :
		Entidade(texturePath, id),
		velocidade(v),
		dano(d),
		atirador(nullptr),
		colidiu(false)
	{
	}

	Projetil::~Projetil() {

	}

	void Projetil::setAtirador(Entidade* a)
	{
		atirador = a;
	}

	bool Projetil::getColidiu() const
	{
		return colidiu;
	}

	void Projetil::colidir()
	{
		colidiu = true;
		delete this;
	}

	void Projetil::danificar(Entidades::Personagens::Personagem* p)
	{
		p->setNumVidas(p->getNumVidas() - dano);
	}

	void Projetil::update(float dt)
	{
		setPosition(position.x + (velocidade * dt * direction.x), position.y + (velocidade * dt * direction.y));
		desenhar();
	}

	void Projetil::salvar(std::ostringstream* entrada)
	{
	}

	
}