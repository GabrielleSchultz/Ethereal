#include "Projetil.h"
#include "Jogador.h"

#define WINDOW_LENGHT 1300
#define WINDOW_HEIGHT 660

namespace Entidades
{
	Projetil::Projetil(const char* texturePath, int d, int v, ID id) :
		Entidade(texturePath, id),
		velocidade(v),
		dano(d),
		atirador(nullptr)
	{
	}

	Projetil::~Projetil() {
		atirador = nullptr;
	}

	void Projetil::setAtirador(Entidade* a)
	{
		atirador = a;
	}

	void Projetil::colidir(Entidades::Entidade* e)
	{
		if (e) {
			if (e->getId() != Entidades::ID::espinhos && e->getId() != Entidades::ID::plataforma && e->getId() != Entidades::ID::poca_lagrima
				&& e->getId() != Entidades::ID::projetil && e->getId() != Entidades::ID::vazio) {
				danificar(static_cast<Entidades::Personagens::Personagem*>(e));
			}
			delete this;
		}
	}

	void Projetil::danificar(Entidades::Personagens::Personagem* p)
	{
		p->setNumVidas(p->getNumVidas() - dano);
		if (atirador->getId() == Entidades::ID::jogador) {
			static_cast<Entidades::Personagens::Jogador*>(atirador)->operator++(dano);
		}
	}

	void Projetil::update(float dt)
	{
		/*if (position.x < 0 || position.x > WINDOW_LENGHT || position.y < 0 || position.y > WINDOW_HEIGHT) {

		}*/
		setPosition(position.x + (velocidade * dt * direction.x), position.y + (velocidade * dt * direction.y));
		desenhar();
	}

	void Projetil::salvar(std::ostringstream* entrada)
	{
	}
}