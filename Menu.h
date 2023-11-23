#pragma once

#include <list>

#include "ControleMenu.h"
#include "Estado.h"
#include "Botao.h"

namespace Estados {

	namespace Menus {
		class Menu : public Estados::Estado {
		protected:
			std::list<Botao*> botoes;
			std::list<Botao*>::iterator it_botao;

			Controle::ControleMenu* pControles;


		public:
			Menu();
			~Menu();
			void inicializaIterator();
			void selecionarCima();
			void selecionarBaixo();
		};
	}
}