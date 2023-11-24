#include "ControleMenu.h"
#include "Menu.h"
#include <iostream>

Controle::ControleMenu::ControleMenu() :
	Controller(),
	pMenu(nullptr)
{
	setKeyCommands("up", "down", "enter");
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
			/*if (pMenu->getTipoEstado() == Estados::Tipo::sair)
				pMenu->request_clear();
			else if(pMenu->getTipoEstado() == Estados::Tipo::vazio)
				pMenu->request_pop();
			else
				pMenu->request_push(pMenu->getTipoEstado());*/
		}
	}
	else
		std::cout << "Controle::ControleMenu -> ponteiro nulo" << std::endl;

}

void Controle::ControleMenu::notifyKeyReleased(std::string key)
{
	if (pMenu) {
		//std::cout << "tecla livre" << std::endl;
		if (key == enter)
		{
			if (pMenu->getTipoEstado() == Estados::Tipo::sair)
				pMenu->request_clear();
			else if (pMenu->getTipoEstado() == Estados::Tipo::vazio)
				pMenu->request_pop();
			else
				pMenu->request_push(pMenu->getTipoEstado());
		}
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
