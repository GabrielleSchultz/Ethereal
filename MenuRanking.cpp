#include "MenuRanking.h"

Estados::Menus::MenuRanking::MenuRanking()
{
}

Estados::Menus::MenuRanking::~MenuRanking()
{
}

void Estados::Menus::MenuRanking::cria_botoes()
{
	std::string textos[] = { "voltar", "sair"};

	Estados::Menus::Botao* botao = nullptr;
	for (int i = 0; i < 5; i++) {
		botao = new Estados::Menus::Botao(Math::Vector2Df(650, 50 * i + 500));
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}
