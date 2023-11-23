#include "Texto.h"
using namespace Estados::Menus::ElementosGraficos;

Gerenciadores::Grafico* Texto::pGG(Gerenciadores::Grafico::getGerenciador_Grafico());

Texto::Texto()
{
	texto.setFont(*pGG->getFonte());
	texto.setCharacterSize(80);
	texto.setOrigin(50.f, 50.f);
	texto.setPosition(565.f, 85.f);
	texto.setFillColor(sf::Color::White);
	//texto.setOutlineColor(sf::Color::Black);
	//texto.setOutlineThickness(5.f);
}

Texto::~Texto()
{
	pGG = nullptr;
}

void Texto::setPosicao(Math::Vector2Df pos)
{
	texto.setPosition(pos.x, pos.y);
}

void Texto::setTamanho(int tam)
{
	texto.setCharacterSize(tam);
}

void Texto::setTexto(std::string text)
{
	texto.setString(text);
}

void Texto::desenhar()
{
	pGG->desenharTexto(&texto);
}