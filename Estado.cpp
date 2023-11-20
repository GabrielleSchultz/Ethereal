#include "Estado.h"
#include "Gerenciador_Estados.h"

Estados::Estado::Estado():
	pGE(Gerenciadores::Gerenciador_Estados::getGerenciadorEstados())
{
}

Estados::Estado::~Estado()
{
}

void Estados::Estado::request_push(Estados::Tipo id_estado)
{
}

void Estados::Estado::request_pop()
{
}

void Estados::Estado::request_clear()
{
}
