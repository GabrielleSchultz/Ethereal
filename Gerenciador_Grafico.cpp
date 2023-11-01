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

void Gerenciadores::Grafico::clearWindow(sf::Color color)
{
	if (isWindowOpen())
		janelaPrincipal->clear(color);
}

void Grafico::displayWindow()
{
	if (isWindowOpen())
		janelaPrincipal->display();
}

void Gerenciadores::Grafico::centralizarCamera(Math::Vector2Df center)
{
	cameraJogo.setCenter(sf::Vector2f(center.x, center.y));
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

void Gerenciadores::Grafico::zoomOut(float coef)
{
	cameraJogo.zoom(-coef);
}

void Gerenciadores::Grafico::zoomIn(float coef)
{
	cameraJogo.zoom(coef);
}

sf::RenderWindow* Gerenciadores::Grafico::getWindow()
{
	return janelaPrincipal;
}

//para entidades
void Gerenciadores::Grafico::desenharEnte(std::string filePath, Math::Vector2Df pos)
{
	
}

bool Gerenciadores::Grafico::carregarTextura(std::string filePath)
{
	MapaTextura::iterator map_it = CharactersTextures.begin();

	while (map_it != CharactersTextures.end())
	{
		if ()
	}


	
	return false;
}

//para demais entes (menu, fases, ...)



