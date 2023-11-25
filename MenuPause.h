#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuPause : public Menu {
		private:
			std::string fundo_pause;

		public:
			MenuPause();
			~MenuPause();
			void cria_botoes();
		};
	}

}