#include "Gerenciador_Estados.h"

namespace Gerenciadores
{
	Gerenciador_Estados* Gerenciador_Estados::instancia_pGE(nullptr);

	Gerenciador_Estados::Gerenciador_Estados()
	{
	}
	Gerenciador_Estados::~Gerenciador_Estados()
	{
	}

	Gerenciador_Estados* Gerenciador_Estados::getGerenciadorEstados()
	{
		if (instancia_pGE == nullptr)
			instancia_pGE = new Gerenciadores::Gerenciador_Estados();
		return instancia_pGE;
	}

	void Gerenciador_Estados::criar_estado(Estados::Tipo id)
	{
		Estados::Estado* novo_estado = nullptr;

		switch (id)
		{
		case Estados::Tipo::GameState:
		{
			novo_estado = new Estados::GameState();
			push(static_cast<Estados::Estado*>(novo_estado));
		}
		break;

		case Estados::Tipo::MenuPrincipal:
		{
			novo_estado = new Estados::Menus::MenuPrincipal();
			push(static_cast<Estados::Estado*>(novo_estado));
		}
		break;

		case Estados::Tipo::MenuPause:
		{
			novo_estado = new Estados::Menus::MenuPause();
			push(static_cast<Estados::Estado*>(novo_estado));
		}
		break;
		}
	}

	void Gerenciador_Estados::push(Estados::Estado* estado)
	{
		vetor_estados.push_back(estado);
	}

	void Gerenciador_Estados::pop()
	{
	}

	void Gerenciador_Estados::clear()
	{
	}

	bool Gerenciador_Estados::isEmpty() const
	{
		return vetor_estados.empty();
	}

}