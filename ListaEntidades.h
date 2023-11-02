#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidades::Entidade* pE);
		void remover(Entidades::Entidade* pE);
		void executar();
		void salvar();
		Lista<Entidades::Entidade>::Iterador get_primeiro() const;
	};
}