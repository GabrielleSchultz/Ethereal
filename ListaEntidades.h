#pragma once
#include "Lista.h"
#include "Entidade.h"
#include "json.h"

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> LEs;
	public:
		ListaEntidades();
		~ListaEntidades();
		void incluir(Entidades::Entidade* pE);
		void remover(Entidades::Entidade* pE);
		void executar(float dt);
		const int getTamanho() const;
		void clear();
		void salvar(nlohmann::ordered_json& entrada);
		Lista<Entidades::Entidade>::Iterador get_primeiro() const;
		Lista<Entidades::Entidade>::Iterador inicio() const;
		Lista<Entidades::Entidade>::Iterador fim() const;
	};
}