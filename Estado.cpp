#include "Estado.h"
#include "Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Estados* Estados::Estado::pGE(NULL);

Estados::Estado::Estado()
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
