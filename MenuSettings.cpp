#include "MenuSettings.h"

#define QTD_BOTOES 3

Estados::Menus::MenuSettings::MenuSettings()
{
	bolha = "Assets/Sprites/select.png";
	pGG->carregarTextura(bolha);
	titulo.setTexto("Settings");
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
	posicoes[0] = Math::Vector2Df(365, 246); 
	posicoes[1] = Math::Vector2Df(365, 346);
}

Estados::Menus::MenuSettings::~MenuSettings()
{
}

void Estados::Menus::MenuSettings::desenhar()
{
	pGG->desenhar(fundo, Math::Vector2Df(0, 0));
	titulo.desenhar();
	for (int i = 0; i < botoes.size(); i++)
	{
		botoes[i]->desenhar();
	}
	//pGG->desenhar(bolha, Math::Vector2Df(600, 250));
	
	pGG->desenhar(bolha, posicoes[(int)Estados::Estado::getMultiplayer()]);
}

void Estados::Menus::MenuSettings::cria_botoes()
{
	std::string textos[QTD_BOTOES] = {"1 jogador", "2 jogadores", "voltar"};
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::singleplayer, Estados::Tipo::multiplayer, Estados::Tipo::vazio};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650, 100 * i + 250), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}