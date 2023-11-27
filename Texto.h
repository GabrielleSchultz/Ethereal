#pragma once

#include "Gerenciador_Grafico.h"

//baseado fortemente no código do repositório TimeAdventure++, desenvolvido pela dupla Isabela e Jean

namespace Estados {
	namespace Menus {
		namespace ElementosGraficos {
			class Texto {
			private:
				sf::Text texto;
				static Gerenciadores::Grafico* pGG;
			public:
				Texto();
				~Texto();

				void setPosicao(Math::Vector2Df pos);
				void setTamanho(int tam);
				void setTexto(std::string text);
				void desenhar();
			};
		}
	}
}