#pragma once

#include "Inimigo.h"
#include "Projetil.h"

namespace Entidades {
	namespace Personagens {
		class Tristeza : public Inimigo {
		private:
			Listas::ListaEntidades projeteis;
			int lancamento;
			float x_maximo;
			float x_minimo;
		public:
			Tristeza(int nv = 10, int mal = 1, const char* texturePath = "Assets/Sprites/sadness_teste.png", ID id = ID::inimigo_tristeza);
			~Tristeza();
			void executar();
			void danificar(Jogador* p);
			void salvar(nlohmann::ordered_json& entrada);
			void update(float dt);
			void lancar_projetil();
			void colidir(Entidades::Entidade* e);
			Listas::ListaEntidades* getProjeteis();
			void setMovimentacao(const float x);
		};
	}
}