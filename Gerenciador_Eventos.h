#pragma once

#include <SFML/Graphics.hpp>
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Inputs.h"

namespace Gerenciadores {
	class Eventos{
	private:
		Gerenciadores::Grafico* pGerenciadorGrafico;
		Gerenciadores::Input* pGerenciadorEntradas;
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