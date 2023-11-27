#include "Gerenciador_Estados.h"

#include "GameState.h"
#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MenuRanking.h"
#include "MenuFases.h"
#include "MenuSettings.h"
#include "MenuGameOver.h"

namespace Gerenciadores
{
	Gerenciador_Estados* Gerenciador_Estados::instancia_pGE(nullptr);

	Gerenciador_Estados::Gerenciador_Estados() :
	vetor_estados(),
	lista_pendencias(),
	fila_delecao()
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
			aux_pendencia = lista_pendencias.back();
			lista_pendencias.pop_back();
			delete(aux_pendencia);
		}
		lista_pendencias.clear();

		Estados::Estado* aux_delete = nullptr;
		while (fila_delecao.size() != 0) {
			aux_delete = fila_delecao.back();
			fila_delecao.pop_back();
			delete(aux_delete);
		}
		fila_delecao.clear();

		instancia_pGE = nullptr;
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
			novo_estado = new Estados::GameState();
			break;

		case Estados::Tipo::MenuPrincipal:
			novo_estado = new Estados::Menus::MenuPrincipal();
			break;

		case Estados::Tipo::MenuFases:
			novo_estado = new Estados::Menus::MenuFases();
			break;

		case Estados::Tipo::Fase1:
			novo_estado = new Estados::GameState(1);
			break;

		case Estados::Tipo::Fase2:
			novo_estado = new Estados::GameState(2);
			break;

		case Estados::Tipo::carregarjogo:
			novo_estado = new Estados::GameState(3);
			break;

		case Estados::Tipo::MenuPause:
		{
			Estados::Estado* pGameState = vetor_estados[vetor_estados.size() - 1];
			if (pGameState)
				novo_estado = new Estados::Menus::MenuPause(dynamic_cast<Estados::GameState*>(pGameState));
			break;
		}

		case Estados::Tipo::MenuRanking:
			novo_estado = new Estados::Menus::MenuRanking();
			break;
		case Estados::Tipo::MenuSettings:
			novo_estado = new Estados::Menus::MenuSettings();
			break;
		case Estados::Tipo::Gameover:
			novo_estado = new Estados::Menus::MenuGameOver();
		}

		vetor_estados.push_back(static_cast<Estados::Estado*>(novo_estado));
	}

	void Gerenciador_Estados::push(Estados::Tipo id)
	{
		Acoes_Pendentes* aux = new Acoes_Pendentes;
		aux->acao = Push;
		aux->ID = id;
		lista_pendencias.push_back(aux);
	}

	void Gerenciador_Estados::pop()
	{
		Acoes_Pendentes* aux = new Acoes_Pendentes;
		aux->acao = Pop;
		aux->ID = Estados::Tipo::vazio;
		lista_pendencias.push_back(aux);
	}

	void Gerenciador_Estados::clear()
	{
		Acoes_Pendentes* aux = new Acoes_Pendentes;
		aux->acao = Clear;
		aux->ID = Estados::Tipo::vazio;
		lista_pendencias.push_back(aux);
	}

	void Gerenciador_Estados::aplicar_pendencias()
	{
		for (Acoes_Pendentes* it : lista_pendencias)
		{
			switch (it->acao)
			{
			case Push:
			{
				criar_estado(it->ID);
				vetor_estados[vetor_estados.size() - 2]->setAtivo(false);
				//std::cout << "criou pendencia push" << std::endl;
				//std::cout << "setou falso" << std::endl;
			}
			break;
			case Pop:
			{
				Estados::Estado* aux = vetor_estados[vetor_estados.size() - 1];
				vetor_estados[vetor_estados.size() - 1]->setAtivo(false);
				vetor_estados.pop_back();
				fila_delecao.push_back(aux);
				vetor_estados[vetor_estados.size() - 1]->setAtivo(true);
				//std::cout << "criou pendencia pop" << std::endl;
				//std::cout << "setou true" << std::endl;
			}
			break;
			case Clear:
			{
				Estados::Estado* aux_estado = nullptr;
				while (vetor_estados.size() != 0) {
					aux_estado = vetor_estados.back();
					vetor_estados.pop_back();
					fila_delecao.push_back(aux_estado);
				}
				vetor_estados.clear();

			}
			break;
			}
		}
		lista_pendencias.clear();
	}

	void Gerenciador_Estados::executar(float dt)
	{
		aplicar_pendencias();
		if (!isEmpty())
			vetor_estados[vetor_estados.size() - 1]->executar(dt);
	}

	bool Gerenciador_Estados::isEmpty() const
	{
		return vetor_estados.empty();
	}
}