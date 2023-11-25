#pragma once

#include "Inimigo.h"

#include <vector>

namespace Entidades {
	namespace Personagens {
		class Vinganca : public Inimigo {
		private:
			int teletransporta;
			Listas::ListaEntidades projeteis;
			std::vector<Entidades::Entidade*> projeteis_lancados;
			int lancamento;
		public:
			Vinganca(int nv = 200, int mal = 100, const char* texturePath = "Assets/Sprites/boss.png", ID id = ID::boss);
			~Vinganca();
			void executar();
			void danificar(Jogador* p);
			void colidir(Entidades::Entidade* e);
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& entrada);
			void update(float dt);
			void teletransporte();
			void lancar_projeteis();
			void remover_projeteis();
			Listas::ListaEntidades* getProjeteis();
		};
	}
}