#pragma once
#include "Personagem.h"
#include "ListaEntidades.h"

namespace Entidades {

	class Projetil : public Entidade, public Tipo::Dinamica {

	private:
		int dano;
		bool colidiu;
		Entidade* atirador;

	public:
		Projetil(const char* texturePath = "", int d = 0, int v = 5, ID id = ID::projetil);
		~Projetil();
		void setAtirador(Entidade* a);
		void colidir(Entidades::Entidade* e);
		bool getColidiu();
		void danificar(Entidades::Personagens::Personagem* p);
		void update(float dt);
		void salvar(nlohmann::ordered_json& entrada);
		void carregar(nlohmann::ordered_json& saida){}
		void carregar(nlohmann::ordered_json& saida, Listas::ListaEntidades* lista, Entidades::Entidade* pAtirador);
	};

}