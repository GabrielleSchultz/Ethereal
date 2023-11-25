#pragma once
#include "Entidade.h"
#include "Entidade_Dinamica.h"

namespace Entidades {
	namespace Personagens {
		class Personagem : public Entidade, public Tipo::Dinamica {
		protected:
			int num_vidas;

		public:
			Personagem(int nv = 0, const char* texturePath = "", ID id = ID::vazio);
			~Personagem();
			bool getVivo();
			int getNumVidas() const;
			void setNumVidas(const int nv);
			virtual void colidir(Entidades::Entidade* e) = 0;
			virtual void update(float dt = 0) = 0;
			void salvarPersonagem(nlohmann::ordered_json& entrada);
			virtual void salvar(nlohmann::ordered_json& entrada) = 0;
			void carregarDadosPersonagem(nlohmann::ordered_json& saida);
			virtual void carregar(nlohmann::ordered_json& saida) = 0;

		};
	}
}