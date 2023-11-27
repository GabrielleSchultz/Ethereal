#pragma once

#include "Gerenciador_Grafico.h"
#include "Estado.h"

//baseado fortemente no código do repositório TimeAdventure++, desenvolvido pela dupla Isabela e Jean

namespace Estados {
	namespace Menus {
		namespace ElementosGraficos {
			class Botao {
			private:
				static Gerenciadores::Grafico* pGG;
				sf::RectangleShape botao;
				sf::Text texto;
				Estados::Tipo tipo_estado;

				bool selecionado;

			public:
				Botao(const Math::Vector2Df pos, Tipo tipo = Tipo::vazio);
				~Botao();
				void setPosicao(Math::Vector2Df pos);
				void setTexto(const std::string text);
				void desenhar();
				void setSelecionado(bool b);
				Estados::Tipo getTipo() const;
			};
		}
	}
}