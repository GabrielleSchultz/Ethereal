#pragma once

#include <SFML/Graphics.hpp>

namespace Gerenciadores {
	class Eventos{
	private:
		sf::Event event;
		sf::RenderWindow* pJanela;
	public:
		Eventos();
		~Eventos();


	};
}