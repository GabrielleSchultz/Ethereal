#include "Ente.h"

int Ente::cont_id(0);

Ente::Ente(): id(cont_id)
{
	cont_id++;
}

Ente::~Ente()
{
}


