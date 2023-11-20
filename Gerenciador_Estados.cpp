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
		}
	}

	void Gerenciador_Estados::push(Estados::Tipo id)
	{
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