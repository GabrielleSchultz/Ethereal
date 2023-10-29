#include "Ente.h"

int Ente::cont_id(0);


Ente::Ente() : id(cont_id),
pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico())
{
	cont_id++;
}

Ente::~Ente()
{
}

void Ente::desenhar()
{
	pGerenciadorGrafico->desenharEnte(this);
}


