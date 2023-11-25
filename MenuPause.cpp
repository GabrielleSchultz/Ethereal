#include "MenuPause.h"

#define	QTD_BOTOES 3

Estados::Menus::MenuPause::MenuPause() : Menu()
{
	titulo.setTexto("Pause");
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuPause::~MenuPause()
{
}

void Estados::Menus::MenuPause::cria_botoes()
{
	std::string textos[QTD_BOTOES] = {"salvar", "voltar", "sair"};
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::vazio, Estados::Tipo::vazio, Estados::Tipo::sair };

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 200.f));
		botao->setTexto(textos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuPause::desenhar()
{
	//pGG->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0, 0));
	titulo.desenhar();
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}
}
