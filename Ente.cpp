#include "Ente.h"

int Ente::cont_id(0);
Gerenciadores::Grafico* Ente::pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico());

Ente::Ente() : 
	_id(cont_id)
{
	cont_id++;
}

Ente::~Ente()
{
	pGerenciadorGrafico = nullptr;
}

