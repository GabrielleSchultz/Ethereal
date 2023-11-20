#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "Tristeza.h"

namespace Gerenciadores
{
	Colisoes* Colisoes::instancia_pGC(nullptr);

	Colisoes::Colisoes() :
		inimigos(nullptr), jogadores(nullptr)
	{

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

	void Colisoes::setListaJogadores(Listas::ListaEntidades* j)
	{
		jogadores = j;
	}

	bool Colisoes::Colisao(Entidades::Entidade* e1, Entidades::Entidade* e2)
	{
		// direita e1 < esquerda e2
		// esquerda e1 > direita e2
		// top e1 > bottom e2
		// bottom e1 < top e2
		if ((e1->getPosition().x + e1->getTamanho().x) < e2->getPosition().x ||
			e1->getPosition().x > (e2->getPosition().x + e2->getTamanho().x) ||
			e1->getPosition().y > (e2->getPosition().y + e2->getTamanho().y) ||
			(e1->getPosition().y + e1->getTamanho().y) < e2->getPosition().y)
			return false;
		return true;
	}

	void Colisoes::ColisaoJogInim()
	{
		Listas::Lista<Entidades::Entidade>::Iterador jog = nullptr;
		Entidades::Entidade* jogador = nullptr;

		Listas::Lista<Entidades::Entidade>::Iterador it = nullptr;
		Entidades::Entidade* inim = nullptr;

		int j = 0, i = 0;
		for (jog = jogadores->get_primeiro(), j = 0; j < jogadores->getTamanho(); jog.operator++(), j++) {
			jogador = jog.operator*();
			for (it = inimigos->get_primeiro(), i = 0; i < inimigos->getTamanho(); it.operator++(), i++) {
				inim = it.operator*();
				if (Colisao(inim, jogador)) {
					static_cast<Entidades::Personagens::Jogador*>(jogador)->colidir();
					static_cast<Entidades::Personagens::Inimigo*>(inim)->colidir();
					static_cast<Entidades::Personagens::Inimigo*>(inim)->danificar(static_cast<Entidades::Personagens::Jogador*>(jogador));
				}
			}
		}
	}
	void Colisoes::ColisaoProjInim()
	{
		Listas::Lista<Entidades::Entidade>::Iterador jog = nullptr;
		Entidades::Entidade* jogador = nullptr;

		int j = 0, i = 0, p = 0;
		for (jog = jogadores->get_primeiro(), j = 0; j < jogadores->getTamanho(); jog.operator++(), j++) {
			jogador = jog.operator*();

			Listas::ListaEntidades* projeteis = static_cast<Entidades::Personagens::Jogador*>(jogador)->getProjeteis();
			Listas::Lista<Entidades::Entidade>::Iterador it = nullptr;
			Entidades::Entidade* inim = nullptr;

			Listas::Lista<Entidades::Entidade>::Iterador pro = nullptr;
			Entidades::Entidade* proj = nullptr;

			for (it = inimigos->get_primeiro(), i = 0; i < inimigos->getTamanho(); it.operator++(), i++) {
				inim = it.operator*();
				for (pro = projeteis->get_primeiro(), p = 0; p < projeteis->getTamanho(); pro.operator++(), p++) {
					proj = pro.operator*();
					if (Colisao(inim, proj)) {
						projeteis->remover(proj);
						static_cast<Entidades::Projetil*>(proj)->danificar(static_cast<Entidades::Personagens::Personagem*>(inim));
						static_cast<Entidades::Personagens::Personagem*>(proj)->colidir();
						static_cast<Entidades::Personagens::Personagem*>(inim)->colidir();
					}
				}
			}
		}
	}
	void Colisoes::ColisaoProjJog()
	{
		Listas::Lista<Entidades::Entidade>::Iterador jog = nullptr;
		Entidades::Entidade* jogador = nullptr;

		int j = 0, i = 0, p = 0;
		for (jog = jogadores->get_primeiro(), j = 0; j < jogadores->getTamanho(); jog.operator++(), j++) {
			jogador = jog.operator*();

			Listas::Lista<Entidades::Entidade>::Iterador it = nullptr;
			Entidades::Entidade* inim = nullptr;

			Listas::ListaEntidades* projeteis = nullptr;
			Listas::Lista<Entidades::Entidade>::Iterador pro = nullptr;
			Entidades::Entidade* proj = nullptr;

			for (it = inimigos->get_primeiro(), i = 0; i < inimigos->getTamanho(); it.operator++(), i++) {
				inim = it.operator*();

				if (inim->getId() == Entidades::ID::inimigo_tristeza) {

					projeteis = static_cast<Entidades::Personagens::Tristeza*>(inim)->getProjeteis();

					for (pro = projeteis->get_primeiro(), p = 0; p < projeteis->getTamanho(); pro.operator++(), p++) {
						proj = pro.operator*();
						if (Colisao(proj, jogador)) {
							projeteis->remover(proj);
							static_cast<Entidades::Projetil*>(proj)->danificar(static_cast<Entidades::Personagens::Personagem*>(jogador));
							static_cast<Entidades::Personagens::Personagem*>(proj)->colidir();
						}
					}
				}
			}
		}
	}
}