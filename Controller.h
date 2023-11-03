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
	virtual void notifyPressed(std::string key) = 0;
	virtual void notifyReleased(std::string key) = 0;
};
