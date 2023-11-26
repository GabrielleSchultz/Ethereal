#pragma once

#include "Menu.h"

namespace Estados {
	namespace Menus {

		class MenuFases : public Menu {
		private:
			std::string camada_fundo_estrelas;

		public:
			MenuFases();
			~MenuFases();
			void cria_botoes();
			void desenhar();
		};

	}
}