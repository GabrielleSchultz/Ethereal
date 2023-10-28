#include "Ente.h"

#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;

#define WINDOW_LENGHT 1180
#define WINDOW_HEIGHT 620


Grafico* Grafico::instancia_pGG(NULL);

Grafico::Grafico() :
janelaPrincipal(sf::VideoMode(WINDOW_LENGHT, WINDOW_HEIGHT), "", sf::Style::Default)
{
}

Grafico::~Grafico()
{
}

Grafico* Grafico::getGerenciador_Grafico()
{
	//no caso de multithread, usar um thread lock
	if (instancia_pGG == NULL)
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
	if (isWindowOpen())
		janelaPrincipal.clear();
}

void Grafico::displayWindow()
{
	if (isWindowOpen())
		janelaPrincipal.display();
}

void Grafico::centralizarCamera()
{
	//...cameraJogo();
}

void Grafico::setWindowTitle(std::string titulo)
{
	janelaPrincipal.setTitle(titulo);
}





