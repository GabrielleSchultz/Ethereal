#include "Menu.h"

Estados::Menus::Menu::Menu() :
    Estado(),
    botoes(),
    it_botao()
{
    pControles = new Controle::ControleMenu();
    pControles->setMenu(this);
}

Estados::Menus::Menu::~Menu()
{
}

void Estados::Menus::Menu::inicializaIterator()
{
    try {
        it_botao = botoes.begin();
        (*it_botao)->setSelecionado(true);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return;
        //exit(1); muito extremo
    }
}

void Estados::Menus::Menu::selecionarCima()
{
    (*it_botao)->setSelecionado(false);
    if (it_botao == botoes.begin())
        it_botao = botoes.end();
    it_botao--;
    (*it_botao)->setSelecionado(true);
}

void Estados::Menus::Menu::selecionarBaixo()
{
    (*it_botao)->setSelecionado(false);
    it_botao++;
    if (it_botao == botoes.end())
        it_botao = botoes.begin();
    (*it_botao)->setSelecionado(true);
}
