#include "Projetil.h"
#include "Jogador.h"
#include "Tristeza.h"
#include "Vinganca.h"

namespace Entidades
{
	Projetil::Projetil(const char* texturePath, int d, int v, ID id) :
		Entidade(texturePath, id),
		dano(d),
		atirador(nullptr)
	{
		setVelocidade(v, v);
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
		setPosition(position.x + (currentVelocity.x * dt * direction.x), position.y + (currentVelocity.y * dt * direction.y));
		desenhar();
	}

	void Projetil::salvar(nlohmann::ordered_json& entrada)
	{
		entrada["posicao_projetil"] = { {"pos x", position.x},{"pos y", position.y} };
		entrada["velocidade_projetil"] = { {"vel x", currentVelocity.x},{"vel y", currentVelocity.y} };
	}

}