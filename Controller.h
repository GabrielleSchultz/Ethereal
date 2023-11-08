#pragma once
#include "Gerenciador_Inputs.h"

//Observer - Interface

class Controllers
{
protected:
	Gerenciadores::Input* pGerenciadorInput;
public:
	Controllers() :
		pGerenciadorInput(Gerenciadores::Input::getGerenciador_Inputs()) {}
	~Controllers() {}
	virtual void notifyKeyPressed(std::string key) = 0;
	virtual void notifyKeyReleased(std::string key) = 0;
};
