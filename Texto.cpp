#include "Texto.h"

Gerenciadores::Grafico* Estados::Menus::Texto::pGG(Gerenciadores::Grafico::getGerenciador_Grafico());

Estados::Menus::Texto::Texto()
{
	texto.setFont(*pGG->getFonte());
	texto.setCharacterSize(80);
	texto.setOrigin(50.f, 50.f);
	texto.setPosition(565.f, 85.f);
	texto.setFillColor(sf::Color::White);
	//texto.setOutlineColor(sf::Color::Black);
	//texto.setOutlineThickness(5.f);
}

Estados::Menus::Texto::~Texto()
{
	pGG = nullptr;
}

void Estados::Menus::Texto::setPosicao(Math::Vector2Df pos)
{
	texto.setPosition(pos.x, pos.y);
}

void Estados::Menus::Texto::setTamanho(int tam)
{
	texto.setCharacterSize(tam);
}

void Estados::Menus::Texto::setTexto(std::string text)
{
	texto.setString(text);
}

void Estados::Menus::Texto::desenhar()
{
	pGG->desenharTexto(&texto);
}