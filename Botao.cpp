#include "Botao.h"

#define TAMANHO_TEXTO 20

Estados::Menus::Botao::Botao(const Math::Vector2Df tam, const Math::Vector2Df pos, const std::string tex):
	Ente(),
	tamanho(tam),
	posicao(pos),
	textura(tex),
	selecionado(false)
{
	pGerenciadorGrafico->carregarTextura(textura);
}

Estados::Menus::Botao::~Botao() {

}

void Estados::Menus::Botao::setTexto(std::string text)
{
	texto.setString(text);
	// pegar fonte
	texto.setCharacterSize(TAMANHO_TEXTO);

	sf::FloatRect textRect = texto.getLocalBounds();
	texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	texto.setPosition(posicao.x, posicao.y);
	texto.setFillColor(sf::Color::White);
}

void Estados::Menus::Botao::desenhar() {
	pGerenciadorGrafico->desenharForma(posicao, tamanho, textura);
	pGerenciadorGrafico->desenharTexto(texto);
}

void Estados::Menus::Botao::executar(float dt)
{
	desenhar();
}

void Estados::Menus::Botao::setSelecionado(bool b)
{
	selecionado = b;
	// mudar cor texto dependendo se tá selecionado ou n (???)
}
