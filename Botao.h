#pragma once

#include "Gerenciador_Grafico.h"
#include "Estado.h"

namespace Estados {
	namespace Menus {
		class Botao{
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
			void setTexto(std::string text);
			void desenhar();
			void setSelecionado(bool b);
			Estados::Tipo getTipo() const;
		};
	}
}