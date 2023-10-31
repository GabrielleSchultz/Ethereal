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

//para entidades
void Gerenciadores::Grafico::desenharEnte(std::string filePath, Math::Vector2Df pos)
{
	if (!carregarTextura(filePath))
	{
		std::cout << "Falha ao carregar textura" << std::endl;
	}
}

bool Gerenciadores::Grafico::carregarTextura(std::string filePath)
{
	MapaTextura::iterator map_it;


	
	return false;
}

//para demais entes (menu, fases, ...)



