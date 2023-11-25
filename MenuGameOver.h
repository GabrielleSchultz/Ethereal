#pragma once
#include "Menu.h"
#include "Texto.h"

namespace Estados {
	namespace Menus {

		class MenuGameOver : public Menu
		{
		private:
			std::string fundo_gameover;

		public:
			MenuGameOver();
			~MenuGameOver();
			void cria_botoes();
		};
	}

}