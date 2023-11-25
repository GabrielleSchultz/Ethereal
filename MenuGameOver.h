#pragma once
#include "Menu.h"
#include "Texto.h"

namespace Estados {
	namespace Menus {

		class MenuGameOver : public Menu
		{
		private:
			// inventar algo

		public:
			MenuGameOver();
			~MenuGameOver();
			void cria_botoes();
		};
	}

}