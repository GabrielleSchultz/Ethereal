#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Inimigo.h"

namespace Gerenciadores
{
	Colisoes* Colisoes::instancia_pGC(nullptr);

	Colisoes::Colisoes():
	inimigos(nullptr){

	}

	Colisoes::~Colisoes()
	{
	}

	Colisoes* Colisoes::getGerenciador_Colisoes()
	{
		if (instancia_pGC == nullptr)
			instancia_pGC = new Gerenciadores::Colisoes();
		return instancia_pGC;
	}

	void Colisoes::setListaInimigos(Listas::ListaEntidades* i)
	{
		inimigos = i;
	}

	bool Colisoes::Colisao(Entidades::Entidade* e1, Entidades::Entidade* e2)
	{
		// direita e1 < esquerda e2
		// esquerda e1 > direita e2
		// top e1 > bottom e2
		// bottom e1 < top e2
		if( (e1->getPosition().x + e1->getTamanho().x) < e2->getPosition().x ||
			e1->getPosition().x > (e2->getPosition().x + e2->getTamanho().x) ||
			e1->getPosition().y > (e2->getPosition().y + e2->getTamanho().y) ||
			(e1->getPosition().y + e1->getTamanho().y) < e2->getPosition().y)
			return false;
		return true;
	}

	void Colisoes::ColisaoJogInim(Entidades::Personagens::Jogador* jog)
	{
		Listas::Lista<Entidades::Entidade>::Iterador it = nullptr;
		Entidades::Entidade* inim = nullptr;
		for (it = inimigos->get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
			inim = it.operator*();
			if (Colisao(inim, jog)) {
				jog->setPosition(jog->getPosition().x - 100, jog->getPosition().y);
			}
		}
	}

}