#pragma once
#include "Gerenciador_Inputs.h"

//Observer - Interface
//baseado fortemente no c�digo do monitor Matheus Burda

class Controller
{
protected:
	Gerenciadores::Input* pGerenciadorInput;
public:
	Controller() :
		pGerenciadorInput(Gerenciadores::Input::getGerenciador_Inputs()) {}
	~Controller() {}
	virtual void notifyKeyPressed(std::string key) = 0;
	virtual void notifyKeyReleased(std::string key) = 0;
};
