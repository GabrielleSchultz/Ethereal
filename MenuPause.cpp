#include "MenuPause.h"

#define	QTD_BOTOES 3

Estados::Menus::MenuPause::MenuPause(GameState* pFase) : Menu(),
pFase_atual(pFase)
{
	fundo_pause = "Assets/Backgrounds/pausar.png";
	setFundo(fundo_pause);
	titulo.setTexto("Pause");
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuPause::~MenuPause()
{
	pFase_atual = nullptr;
}

void Estados::Menus::MenuPause::cria_botoes()
{
	std::string textos[QTD_BOTOES] = { "salvar", "voltar", "sair" };
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::save, Estados::Tipo::vazio, Estados::Tipo::sair };

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 200.f), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuPause::salvar_jogo()
{
	if (pFase_atual) {
		pFase_atual->salvar_jogo();
	}
}
