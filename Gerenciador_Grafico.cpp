#include "Ente.h"

#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;

#define WINDOW_LENGHT 1180
#define WINDOW_HEIGHT 620


Grafico* Grafico::instancia_pGG(NULL);

Grafico::Grafico()
{
	janelaPrincipal = new sf::RenderWindow(sf::VideoMode(WINDOW_LENGHT, WINDOW_HEIGHT), "", sf::Style::Titlebar | sf::Style::Close);
}

Grafico::~Grafico()
{
	delete janelaPrincipal;
}

//singleton:
Grafico* Grafico::getGerenciador_Grafico()
{
	//no caso de multithread, usar um thread lock
	if (instancia_pGG == NULL)
		instancia_pGG = new Grafico();
	return instancia_pGG;
}

bool Grafico::isWindowOpen()
{
	if (janelaPrincipal->isOpen())
		return true;
	return false;
}

void Grafico::clearWindow()
{
	if (isWindowOpen())
		janelaPrincipal->clear();
}

void Grafico::displayWindow()
{
	if (isWindowOpen())
		janelaPrincipal->display();
}

void Grafico::centralizarCamera()
{
	//...
}

void Grafico::setWindowTitle(std::string titulo)
{
	janelaPrincipal->setTitle(titulo);
}

void Grafico::closeWindow()
{
	if (isWindowOpen())
		janelaPrincipal->close();
}

sf::RenderWindow* Gerenciadores::Grafico::getWindow()
{
	return janelaPrincipal;
}

void Grafico::desenharEnte(Ente* pEnte)
{
	
}

void Gerenciadores::Grafico::desenharTexto(sf::Text* texto)
{
}





