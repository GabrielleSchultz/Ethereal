#pragma once

//referencia: livro SFML Game Development - Arthur Moreira, Jan Haller

#include <vector>
#include "Estado.h"

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
		void criar_estado(Estados::Tipo id);
		void push(Estados::Tipo id);
		void pop();
		void clear();

		bool isEmpty() const;
	};
}