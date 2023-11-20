#include "Ente.h"

int Ente::cont_id(0);


Ente::Ente() : _id(cont_id),
pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico())
{
	cont_id++;
}

Ente::~Ente()
{
	pGerenciadorGrafico = nullptr;
}

