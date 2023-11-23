#include "ControleMenu.h"
#include "Menu.h"
#include <iostream>

Controle::ControleMenu::ControleMenu():
	Controller(),
	pMenu(nullptr)
{
	setKeyCommands("up", "down", "space");
	// adicionar aqui, não achei onde adicionava o controle jogador (??)
	pGerenciadorInput->adicionar_observer(this);
}

Controle::ControleMenu::~ControleMenu()
{
	pMenu = nullptr;
}

void Controle::ControleMenu::notifyKeyPressed(std::string key)
{
	if (pMenu) {
		if (key == para_cima)
		{
			pMenu->selecionarCima();
		}

		if (key == para_baixo)
		{
			pMenu->selecionarBaixo();
		}

		if (key == enter)
		{
			// seleciona definitivamente
		}
	}
	else
		std::cout << "Controle::ControleMenu -> ponteiro nulo" << std::endl;

}

void Controle::ControleMenu::notifyKeyReleased(std::string key)
{
	if (pMenu) {
		// . . .
	}
	else
		std::cout << "Controle::ControleMenu -> ponteiro nulo" << std::endl;
}

void Controle::ControleMenu::setKeyCommands(std::string up, std::string down, std::string ent)
{
	para_cima = up;
	para_baixo = down;
	enter = ent;
}

void Controle::ControleMenu::setMenu(Estados::Menus::Menu* m)
{
	if(m)
		pMenu = m;
}
