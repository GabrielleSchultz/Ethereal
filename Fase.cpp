#include <iostream>

#include "Fase.h"

namespace Fases
{

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
		if (type == 'B')
		{
			//cria novo jogador 1
			//passa o jogador para o gerenciador grafico
		}
		else if (/*gamemode == twoPlayers* &&*/ type == 'P')
		{
			//cria novo jogador 2
			//passa o jogador para o gerenciador grafico
		}
		else
			std::cerr << "Erro ao criar jogador. Verificar arquivo de geração de mapa" << std::endl;
	}
}

