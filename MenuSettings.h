#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuSettings : public Menu {
		private:

		public:
			MenuSettings();
			~MenuSettings();
			void desenhar();
			void cria_botoes();
		};

	}
}