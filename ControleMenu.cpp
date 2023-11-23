#include "ControleMenu.h"
#include "Menu.h"
#include <iostream>

Controle::ControleMenu::ControleMenu() :
	Controller(),
	pMenu(nullptr)
{
	setKeyCommands("up", "down", "space");
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
			std::cout << "vai pra cima" << std::endl;
			pMenu->selecionarCima();
		}

		if (key == para_baixo)
		{
			std::cout << "vai pra baixo" << std::endl;
			pMenu->selecionarBaixo();
		}

		if (key == enter)
		{
			pMenu->request_pop();
			if(pMenu->getTipoEstado() != Estados::Tipo::vazio)
				pMenu->request_push(pMenu->getTipoEstado());
		}
	}
	else
		std::cout << "Controle::ControleMenu -> ponteiro nulo" << std::endl;

}

void Controle::ControleMenu::notifyKeyReleased(std::string key)
{
	if (pMenu) {
		std::cout << "tecla livre" << std::endl;
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
	if (m){
		pMenu = m;
		pGerenciadorInput->adicionar_observer(this);
	}
}
