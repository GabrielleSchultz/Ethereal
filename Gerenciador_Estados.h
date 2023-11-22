#pragma once

//referencia: livro SFML Game Development - Arthur Moreira, Jan Haller

#include <vector>

#include "Estado.h"
#include "GameState.h"
#include "MenuPause.h"
#include "MenuPrincipal.h"
#include "MenuRanking.h"

namespace Gerenciadores {
	class Gerenciador_Estados
	{
	public:
		enum Comandos { Push, Pop, Clear };

	private:
		struct Acoes_Pendentes
		{
			Comandos acao;
			Estados::Tipo ID;
		};

		std::vector<Estados::Estado*> vetor_estados;
		std::vector <Acoes_Pendentes> lista_pendencias;

		static Gerenciador_Estados* instancia_pGE;

		Gerenciador_Estados();

	public:
		~Gerenciador_Estados();
		static Gerenciador_Estados* getGerenciadorEstados();
		
		// não tá como privado (???)
		void criar_estado(Estados::Tipo id);
		void aplicarAcoes_Pendentes();

		void push(Estados::Estado* estado);
		void pop();
		void clear();

		bool isEmpty() const;
	};
}