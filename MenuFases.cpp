#include "MenuFases.h"

#define QTD_BOTOES 3

Estados::Menus::MenuFases::MenuFases()
{
	camada_fundo_estrelas = "Assets/Backgrounds/Stars-Big_1_1_PC.png";
	pGG->carregarTextura(camada_fundo_estrelas);
	titulo.setTexto("Novo jogo");
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuFases::~MenuFases()
{
}

void Estados::Menus::MenuFases::cria_botoes()
{
	std::string textos[QTD_BOTOES] = { "ressonancia", "refracao", "voltar" };
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::Fase1, Estados::Tipo::Fase2, Estados::Tipo::vazio };

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650, 50 * i + 200), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuFases::desenhar()
{
	pGG->desenhar(fundo, Math::Vector2Df(0, 0));
	titulo.desenhar();
	for (int i = 0; i < botoes.size(); i++)
	{
		botoes[i]->desenhar();
	}
	pGG->desenhar(camada_fundo_estrelas, Math::Vector2Df(0, 0));
}