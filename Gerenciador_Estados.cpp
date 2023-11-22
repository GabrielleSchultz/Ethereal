#include "Gerenciador_Estados.h"

namespace Gerenciadores
{
	Gerenciador_Estados* Gerenciador_Estados::instancia_pGE(nullptr);

	Gerenciador_Estados::Gerenciador_Estados()
	{
	}
	Gerenciador_Estados::~Gerenciador_Estados()
	{
		Estados::Estado* aux_estado = nullptr;
		while (vetor_estados.size() != 0) {
			aux_estado = vetor_estados.back();
			vetor_estados.pop_back();
			delete(aux_estado);
		}
		vetor_estados.clear();

		Acoes_Pendentes* aux_pendencia = nullptr;
		while (lista_pendencias.size() != 0) {
			aux_pendencia = &lista_pendencias.back();
			lista_pendencias.pop_back();
			delete(aux_pendencia);
		}
		lista_pendencias.clear();
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
		case Estados::Tipo::Ranking:
		{
			novo_estado = new Estados::Menus::MenuRanking();
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
		vetor_estados.pop_back();
	}

	void Gerenciador_Estados::clear()
	{
		vetor_estados.clear();
	}

	void Gerenciador_Estados::aplicar_pendencias()
	{
		/*std::vector <Acoes_Pendentes>::iterator it;

		for (it = lista_pendencias.begin(); it != lista_pendencias.end(); it++)*/
		for(Acoes_Pendentes it : lista_pendencias)
		{
			switch (it.acao)
			{
			case Push:
				criar_estado(it.ID);
				break;
			case Pop:
				pop();
				break;
			case Clear:
				clear();
				break;
			}
		}
		lista_pendencias.clear();
	}

	bool Gerenciador_Estados::isEmpty() const
	{
		return vetor_estados.empty();
	}

}