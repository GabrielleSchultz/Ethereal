#include "MenuGameOver.h"
#define QTD_BOTOES 3

Estados::Menus::MenuGameOver::MenuGameOver() : Menu(),
texto()
{
	titulo.setTexto("Fim de Jogo");
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuGameOver::~MenuGameOver()
{
}

void Estados::Menus::MenuGameOver::cria_botoes()
{
	std::string textos[QTD_BOTOES] = { "voltar ao Menu Principal", "salvar", "sair" };
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::vazio, Estados::Tipo::sair };

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < textos->size(); i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 500.f));
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}
