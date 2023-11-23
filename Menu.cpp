#include "Menu.h"

Gerenciadores::Grafico* Estados::Menus::Menu::pGG(Gerenciadores::Grafico::getGerenciador_Grafico());

Estados::Menus::Menu::Menu() :
    Estado(),
    titulo(),
    botoes(),
    botao_atual(0)
{
    pGG->carregarTextura("Assets/Backgrounds/Menu.png");
    pControles = new Controle::ControleMenu();
    pControles->setMenu(this);
}

Estados::Menus::Menu::~Menu()
{
    /*for (it_botao = botoes.begin(); it_botao != botoes.end(); it_botao++) {
        delete(*it_botao);
    }*/
    for (botao_atual = 0; botao_atual < botoes.size(); botao_atual++) {
        delete botoes[botao_atual];
    }
    botoes.clear();
}

/*void Estados::Menus::Menu::inicializaIterator()
{
    try {
        it_botao = botoes.begin();
        (*it_botao)->setSelecionado(true);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1); //muito extremo
    }
}*/

void Estados::Menus::Menu::selecionarCima()
{
    //std::cout << botao_atual << std::endl;
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

void Estados::Menus::Menu::desenhar()
{
    pGG->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0, 0));
    titulo.desenhar();
    for (int i = 0; i < botoes.size(); i++)
    {
        botoes[i]->desenhar();
    }
}
