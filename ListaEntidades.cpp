#include "ListaEntidades.h"

Listas::ListaEntidades::ListaEntidades() :
	LEs()
{

}

Listas::ListaEntidades::~ListaEntidades() {

}

void Listas::ListaEntidades::incluir(Entidades::Entidade* pE) {
	LEs.incluir(pE);
}

void Listas::ListaEntidades::remover(Entidades::Entidade* pE) {
	LEs.remover(pE);
}

void Listas::ListaEntidades::executar() {
	Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	for (it = get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		aux = it.operator*();
		aux->executar();
	}
}

void Listas::ListaEntidades::salvar() {
	Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	for (it = get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		aux = it.operator*();
		aux->salvar();
	}
}

Listas::Lista<Entidades::Entidade>::Iterador Listas::ListaEntidades::get_primeiro() const {
	return LEs.get_primeiro();
}