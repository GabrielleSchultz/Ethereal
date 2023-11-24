#include "MenuPrincipal.h"

#define QTD_BOTOES 5

Estados::Menus::MenuPrincipal::MenuPrincipal(): Menu(),
	subtitulo()
{
	titulo.setTexto("Ethereal");
	subtitulo.setTexto("echoes of the soul");
	subtitulo.setTamanho(20);
	subtitulo.setPosicao(Math::Vector2Df(666, 180));

	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuPrincipal::~MenuPrincipal()
{
}

void Estados::Menus::MenuPrincipal::cria_botoes()
{
	std::string textos[QTD_BOTOES] = {"novo jogo", "continuar", "settings", "ranking", "sair"};
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::MenuFases, Estados::Tipo::GameState, Estados::Tipo::MenuSettings, Estados::Tipo::MenuRanking, Estados::Tipo::sair};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650, 50 * i + 200), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuPrincipal::desenhar()
{
	pGG->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0, 0));
	titulo.desenhar();
	subtitulo.desenhar();
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}
}
