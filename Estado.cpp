#include "Estado.h"
#include "Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Estados* Estados::Estado::pGE(Gerenciadores::Gerenciador_Estados::getGerenciadorEstados());

Estados::Estado::Estado():
	sair(false)
{
}

Estados::Estado::~Estado()
{
}

void Estados::Estado::request_push(Estados::Tipo id_estado)
{
	pGE->push(id_estado);
}

void Estados::Estado::request_pop()
{
	pGE->pop();
}

void Estados::Estado::request_clear()
{
	pGE->clear();
}
