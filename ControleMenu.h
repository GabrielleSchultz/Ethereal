#pragma once

#include "Controller.h"

namespace Estados {
	namespace Menus {
		class Menu;
	}
}

//Observer Concreto:
namespace Controle{
	class ControleMenu : public Controller
	{
	private:
		Estados::Menus::Menu* pMenu;

		std::string para_cima;
		std::string para_baixo;
		std::string enter;

	public:
		ControleMenu();
		~ControleMenu();
		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);
		void setKeyCommands(std::string up, std::string down, std::string ent);
		void setMenu(Estados::Menus::Menu* m);
	};
}