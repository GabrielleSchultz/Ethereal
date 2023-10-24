#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;

#define WINDOW_LENGHT 1180
#define WINDOW_HEIGHT 620


Grafico* Grafico::instancia_pGG(NULL);

Grafico::Grafico() : janelaPrincipal(sf::VideoMode(WINDOW_LENGHT, WINDOW_HEIGHT), "", sf::Style::Default){}

Grafico::~Grafico()
{
}

Grafico* Grafico::getGerenciador_Grafico()
{
	//no caso de multithread, usar um thread lock
	if (!instancia_pGG)
		instancia_pGG = new Grafico();
	return instancia_pGG;
}

bool Grafico::isWindowOpen()
{
	if (janelaPrincipal.isOpen())
		return true;
	return false;
}

void Grafico::clearWindow()
{
	janelaPrincipal.clear();
}

void Grafico::displayWindow()
{
	janelaPrincipal.display();
}

void Grafico::centralizarCamera()
{
	//...cameraJogo();
}

void Gerenciadores::Grafico::setWindowTitle(std::string titulo)
{
	janelaPrincipal.setTitle(titulo);
}




