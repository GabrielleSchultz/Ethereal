#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuPrincipal : public Menu {
		private:
			ElementosGraficos::Texto subtitulo;

		public:
			MenuPrincipal();
			~MenuPrincipal();
			void cria_botoes();
			void desenhar();
		};

	}

}