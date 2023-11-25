#pragma once

#include "Inimigo.h"

#include <vector>

namespace Entidades {
	namespace Personagens {
		class Vinganca : public Inimigo {
		private:
			int teletransporta;
			const int frequencia_teletransporte;
			static int cont_frequencia;
			bool ativo;

		public:
			Vinganca(int nv = 200, int mal = 100, const char* texturePath = "Assets/Sprites/revenge_boss.png", ID id = ID::boss);
			~Vinganca();
			void executar();
			void danificar(Jogador* p);
			void colidir(Entidades::Entidade* e);
			void salvar(nlohmann::ordered_json& entrada);
			void carregar(nlohmann::ordered_json& entrada);
			void update(float dt);
			void teletransporte();
			void setAtivo(bool b);
			bool getAtivo();
		};
	}
}