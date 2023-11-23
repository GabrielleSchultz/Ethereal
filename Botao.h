#pragma once

#include "Ente.h"

namespace Estados {
	namespace Menus {
		class Botao : public Ente {
		private:
			Math::Vector2Df tamanho;
			Math::Vector2Df posicao;
			const std::string textura;

			sf::Text texto;
			sf::Font fonte;

			bool selecionado;

		public:
			Botao(const Math::Vector2Df tam, const Math::Vector2Df pos, const std::string tex);
			~Botao();
			void setTexto(std::string text);
			void desenhar();
			virtual void executar(float dt);
			virtual void salvar(std::ostringstream* entrada) {}
			void setSelecionado(bool b);
		};
	}
}