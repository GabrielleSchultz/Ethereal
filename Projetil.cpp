#include "Projetil.h"
#include "Jogador.h"
#include "Tristeza.h"
#include "Vinganca.h"

#define WIDTH 1400
#define HEIGHT 670

namespace Entidades
{
	Projetil::Projetil(const char* texturePath, int d, int v, ID id) :
		Entidade(texturePath, id),
		dano(d),
		colidiu(false),
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
			colidiu = true;
		}
	}

	bool Projetil::getColidiu()
	{
		if (position.x > WIDTH || position.x < -30 || position.y > HEIGHT || position.y < -30)
			colidiu = true;
		return colidiu;
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
		entrada["direcao_projetil"] = { {"dir x", direction.x},{"dir y", direction.y} };

	}

	void Projetil::carregar(nlohmann::ordered_json& saida, Listas::ListaEntidades* lista, Entidades::Entidade* pAtirador)
	{
		setPosition(saida["posicao_projetil"]["x"].template get<float>(), saida["posicao_projetil"]["y"].template get<float>());
		setVelocidade(saida["velocidade_projetil"]["x"].template get<float>(), saida["velocidade_projetil"]["y"].template get<float>());
		setDirection(saida["direcao_projetil"]["x"].template get<float>(), saida["direcao_projetil"]["y"].template get<float>());

		setAtirador(pAtirador);
		lista->incluir(this);
	
	}

}