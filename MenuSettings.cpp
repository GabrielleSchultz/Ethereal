#include "MenuSettings.h"

#define QTD_BOTOES 2

Estados::Menus::MenuSettings::MenuSettings()
{
	titulo.setTexto("Settings");
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuSettings::~MenuSettings()
{
}

void Estados::Menus::MenuSettings::desenhar()
{
	pGG->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0, 0));
	titulo.desenhar();
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}
}

void Estados::Menus::MenuSettings::cria_botoes()
{
	std::string textos[QTD_BOTOES] = {"1 jogador", "2 jogadores"};
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::vazio, Estados::Tipo::vazio};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650, 100 * i + 250), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}