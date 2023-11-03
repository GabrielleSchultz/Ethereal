#pragma once
#include "Gerenciador_Inputs.h"

//Observer - Interface

class Controlers
{
protected:
	Gerenciadores::Input* pGerenciadorInput;
public:
	Controlers() :
		pGerenciadorInput(Gerenciadores::Input::getGerenciador_Inputs()) {}
	~Controlers() {}
	virtual void notifyPressed() = 0;
	virtual void notifyReleased() = 0;
};
