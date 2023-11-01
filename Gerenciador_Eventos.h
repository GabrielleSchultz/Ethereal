#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"

namespace Gerenciadores {
	class Eventos{
	private:
		Gerenciadores::Grafico* pGerenciadorGrafico;
		//gerenciador de inputs (input handler)
		sf::RenderWindow* pJanela;

		//singleton:
		static Gerenciadores::Eventos* instancia_pGE;
		Eventos();
	public:
		~Eventos();
		static Gerenciadores::Eventos* getGerenciador_Eventos();

		void pollEvents();

	};
}