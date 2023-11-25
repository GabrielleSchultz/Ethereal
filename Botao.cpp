#include "Botao.h"

#define TAMANHO_TEXTO 20
#define TAMANHOX 600.f
#define TAMANHOY 80.f

using namespace Estados::Menus::ElementosGraficos;

Gerenciadores::Grafico* Estados::Menus::ElementosGraficos::Botao::pGG(Gerenciadores::Grafico::getGerenciador_Grafico());

Botao::Botao(const Math::Vector2Df pos, Estados::Tipo tipo) :
	botao(sf::Vector2f(TAMANHOX, TAMANHOY)),
	texto(),
	tipo_estado(tipo),
	selecionado(false)
{
	botao.setOrigin(TAMANHOX / 2, TAMANHOY / 2);
	botao.setFillColor(sf::Color::Transparent);
	botao.setPosition(pos.x, pos.y);

	texto.setOrigin(TAMANHOX / 2 - 50, TAMANHOY / 2 - 25);
	texto.setFont(*pGG->getFonte());
	texto.setFillColor(sf::Color::White);
	texto.setOutlineColor(sf::Color::Black);
	texto.setCharacterSize(30);
	texto.setPosition(pos.x, pos.y);
	texto.setOutlineThickness(1.f);
}

Botao::~Botao() {

}

void Botao::setPosicao(Math::Vector2Df pos)
{
	botao.setPosition(pos.x, pos.y);
	texto.setPosition(pos.x, pos.y);
}

void Botao::setTexto(const std::string text)
{
	texto.setString(text);
}

void Botao::desenhar() {
	pGG->desenharForma(&botao);
	pGG->desenharTexto(&texto);
}


void Botao::setSelecionado(bool b)
{
	selecionado = b;
	if (b) {
		texto.setFillColor(sf::Color::Black);
		texto.setOutlineColor(sf::Color::White);
		texto.setCharacterSize(32);
	}
	else {
		texto.setFillColor(sf::Color::White);
		texto.setOutlineColor(sf::Color::Black);
		texto.setCharacterSize(30);
	}
}

Estados::Tipo Botao::getTipo() const
{
	std::string str = texto.getString();
	//std::cout << str << std::endl;
	return tipo_estado;
}
