#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuSettings : public Menu {
		private:
			std::string bolha;
			Math::Vector2Df posicoes[2];

		public:
			MenuSettings();
			~MenuSettings();
			void desenhar();
			void cria_botoes();
		};

	}
}