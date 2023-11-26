#pragma once

#include "Menu.h"
#include "GameState.h"

namespace Estados {
	namespace Menus {

		class MenuPause : public Menu {
		private:
			std::string fundo_pause;
			Estados::GameState* pFase_atual;

		public:
			MenuPause(Estados::GameState* pFase = nullptr);
			~MenuPause();
			void cria_botoes();
		};
	}

}