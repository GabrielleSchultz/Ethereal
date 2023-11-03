#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

//inspirado no código do monitor Matheus Burda
//Observer - Subject

class Controllers;

namespace Gerenciadores {

	class Input
	{
	private:

		std::map <sf::Keyboard::Key, std::string> keyMap;
		std::vector <Controllers*> observers;
		static Input* instancia_pGI;
		Input();

	public:
		~Input();
		static Input* getGerenciador_Inputs();
		void notifyKeyPressed(sf::Keyboard::Key key);
		void notifyKeyReleased(sf::Keyboard::Key key);
		void adicionar_observer(Controllers* pObserver);
		void remover_observer(Controllers* pObserver);
		void createKeyMap();
	};
}