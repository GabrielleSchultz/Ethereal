#include <iostream>

#include "Fase.h"
using namespace Fases;

Fase::Fase()
{
}

Fase::~Fase()
{
}

void Fase::executar()
{
	gerenciar_colisoes();
}

void Fase::gerenciar_colisoes()
{
	//...
}

void Fases::Fase::criar_jogador(char type)
{
	if (type == 'P')
	{

	}
	else if (type == 'B')
	{

	}
	else
		std::cerr << "Erro ao criar jogador. Verificar arquivo de geração de mapa" << std::endl;
}

