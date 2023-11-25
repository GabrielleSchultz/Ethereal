#pragma once

#include "Inimigo.h"
#include "Projetil.h"
#include <vector>

namespace Entidades {
	namespace Personagens {
		class Tristeza : public Inimigo {
		private:
			Listas::ListaEntidades projeteis;
			std::vector<Entidades::Entidade*> projeteis_lancados;
			int lancamento;
			float x_maximo;
			float x_minimo;
		public:
			Tristeza(int nv = 10, int mal = 1, const char* texturePath = "Assets/Sprites/sadness_teste.png", ID id = ID::inimigo_tristeza);
			~Tristeza();
			void danificar(Jogador* p);
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& entrada);
			void update(float dt);
			void lancar_projetil();
			void remover_projeteis();
			void colidir(Entidades::Entidade* e);
			Listas::ListaEntidades* getProjeteis();
			void setMovimentacao(const float x);
		};
	}
}