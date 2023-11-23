#include "MenuPrincipal.h"

Estados::Menus::MenuPrincipal::MenuPrincipal():
	subtitulo()
{
	titulo.setTexto("Ethereal");
	subtitulo.setTexto("echoes of the soul");
	subtitulo.setTamanho(20);
	subtitulo.setPosicao(Math::Vector2Df(666, 180));

	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
	//inicializaIterator();
}

Estados::Menus::MenuPrincipal::~MenuPrincipal()
{
}

void Estados::Menus::MenuPrincipal::cria_botoes()
{
	std::string textos[] = { "novo jogo", "continuar", "settings", "ranking", "sair" };
	Estados::Tipo tipos[] = { Estados::Tipo::GameState, Estados::Tipo::GameState, Estados::Tipo::MenuSettings, Estados::Tipo::MenuRanking, Estados::Tipo::vazio};

	Estados::Menus::Botao* botao = nullptr;
	for (int i = 0; i < 5; i++) {
		botao = new Estados::Menus::Botao(Math::Vector2Df(650, 50 * i + 200), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuPrincipal::desenhar()
{
	pGG->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0, 0));
	titulo.desenhar();
	subtitulo.desenhar();
	/*for (it_botao = botoes.begin(); it_botao != botoes.end(); it_botao++) {
		(*it_botao)->desenhar();
	}*/
	for (int i = 0; i < botoes.size(); i++) {
		botoes[i]->desenhar();
	}
}
