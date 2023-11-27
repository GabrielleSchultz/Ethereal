#include "Menu.h"

Gerenciadores::Grafico* Estados::Menus::Menu::pGG(Gerenciadores::Grafico::getGerenciador_Grafico());

Estados::Menus::Menu::Menu() :
    Estado(),
    titulo(),
    botoes(),
    botao_atual(0),
    fundo()
{
    pControles = new Controle::ControleMenu();
    pControles->setMenu(this);
    setFundo("Assets/Backgrounds/Menu.png");
}

Estados::Menus::Menu::~Menu()
{
    for (botao_atual = 0; botao_atual < botoes.size(); botao_atual++) {
        delete botoes[botao_atual];
    }
    botoes.clear();
    pControles = nullptr;
    pGG = nullptr;
}

void Estados::Menus::Menu::selecionarCima()
{
    botoes[botao_atual]->setSelecionado(false);
    if (botao_atual > 0)
        botao_atual--;
    else
        botao_atual = botoes.size() - 1;
    botoes[botao_atual]->setSelecionado(true);
}

void Estados::Menus::Menu::selecionarBaixo()
{
    botoes[botao_atual]->setSelecionado(false);
    if (botao_atual < botoes.size() - 1)
        botao_atual++;
    else
        botao_atual = 0;
    botoes[botao_atual]->setSelecionado(true);
}

Estados::Tipo Estados::Menus::Menu::getTipoEstado() const
{
    return botoes[botao_atual]->getTipo();
}

void Estados::Menus::Menu::executar(float dt)
{
    desenhar();
}

void Estados::Menus::Menu::setFundo(std::string f)
{
    pGG->carregarTextura(f);
    fundo = f;
}

void Estados::Menus::Menu::desenhar()
{
    pGG->desenhar(fundo, Math::Vector2Df(0, 0));
    titulo.desenhar();
    for (int i = 0; i < botoes.size(); i++)
    {
        botoes[i]->desenhar();
    }
}
