#include "MenuGameOver.h"

Estados::Menus::MenuGameOver::MenuGameOver() : Menu(),
texto()
{
	cria_botoes();
}

Estados::Menus::MenuGameOver::~MenuGameOver()
{
}

void Estados::Menus::MenuGameOver::cria_botoes()
{
	std::string textos[] = { "voltar ao Menu Principal", "ranking", "sair"};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < textos->size(); i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 500.f));
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}
