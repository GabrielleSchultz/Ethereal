#include "MenuPause.h"

Estados::Menus::MenuPause::MenuPause()
{
}

Estados::Menus::MenuPause::~MenuPause()
{
}

void Estados::Menus::MenuPause::cria_botoes()
{
	std::string textos[] = { "salvar", "voltar", "sair"};

	Estados::Menus::Botao* botao = nullptr;
	for (int i = 0; i < 5; i++) {
		botao = new Estados::Menus::Botao(Math::Vector2Df(650, 50 * i + 200));
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}
