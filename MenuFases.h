#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuFases : public Menu {
		private:
			//...


		public:
			MenuFases();
			~MenuFases();
			void desenhar();
			void cria_botoes();
		};

	}
}