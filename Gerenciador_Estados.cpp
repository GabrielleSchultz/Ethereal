#include "Gerenciador_Estados.h"

namespace Gerenciadores
{
	Gerenciador_Estados* Gerenciador_Estados::instancia_pGE(nullptr);

	Gerenciador_Estados::Gerenciador_Estados()
	{
		Estados::Estado* aux = nullptr;
		while (vetor_estados.size() != 0) {
			aux = vetor_estados.back();
			delete(aux);
			vetor_estados.pop_back();
		}
		vetor_estados.clear();

		Acoes_Pendentes* aux2 = nullptr;
		while (lista_pendencias.size() != 0) {
			aux2 = &lista_pendencias.back();
			delete(aux2);
			lista_pendencias.pop_back();
		}
		lista_pendencias.clear();
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

	void Gerenciador_Estados::aplicarAcoes_Pendentes()
	{
		//FOREACH(Acoes_Pendentes pendente, lista_pendencias) {
		for(Acoes_Pendentes pendente : lista_pendencias) {
			switch (pendente.acao) {
			case Push:
				criar_estado(pendente.ID);
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

	void Gerenciador_Estados::push(Estados::Estado* estado)
	{
		vetor_estados.push_back(estado);
	}

	void Gerenciador_Estados::pop()
	{
		// vetor_estados.pop_back(); (????)
		vetor_estados.erase(vetor_estados.begin() + vetor_estados.size() - 1);
	}

	void Gerenciador_Estados::clear()
	{
		vetor_estados.clear();
	}

	bool Gerenciador_Estados::isEmpty() const
	{
		return vetor_estados.empty();
	}

}