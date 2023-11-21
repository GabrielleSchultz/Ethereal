#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

//inspirado no código do monitor Matheus Burda
//Observer - Subject

class Controller;

namespace Gerenciadores {

	class Input
	{
	private:

		std::map <sf::Keyboard::Key, std::string> keyMap;
		std::vector <Controller*> observers;
		static Input* instancia_pGI;
		Input();

	public:
		~Input();
		static Input* getGerenciador_Inputs();
		void notifyKeyPressed(sf::Keyboard::Key key);
		void notifyKeyReleased(sf::Keyboard::Key key);
		void adicionar_observer(Controller* pObserver);
		void remover_observer(Controller* pObserver);
		void createKeyMap();
	};
}