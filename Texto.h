#pragma once

#include "Gerenciador_Grafico.h"

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