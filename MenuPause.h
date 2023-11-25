#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuPause : public Menu {
		private:
			//...


		public:
			MenuPause();
			~MenuPause();
			void cria_botoes();
			void desenhar();
		};
	}

}