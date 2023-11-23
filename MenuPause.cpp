#include "MenuPause.h"

Estados::Menus::MenuPause::MenuPause() : Menu()
{
}

Estados::Menus::MenuPause::~MenuPause()
{
}

void Estados::Menus::MenuPause::cria_botoes()
{
	std::string textos[] = { "salvar", "voltar", "sair"};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < textos->size(); i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 200.f));
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}
