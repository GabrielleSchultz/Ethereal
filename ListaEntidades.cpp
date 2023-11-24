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

void Listas::ListaEntidades::executar(float dt) {
	Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	for (it = get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		aux = it.operator*();
		aux->executar(dt);
	}
}

const int Listas::ListaEntidades::getTamanho() const {
	return LEs.getTamanho();
}

void Listas::ListaEntidades::clear()
{
	LEs.clear();
}

void Listas::ListaEntidades::salvar(nlohmann::ordered_json& entrada) {
	Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;

	for (it = get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		nlohmann::ordered_json dados_entidade;
		aux = it.operator*();
		aux->salvar(dados_entidade);
		entrada.push_back(dados_entidade);
	}
}

Listas::Lista<Entidades::Entidade>::Iterador Listas::ListaEntidades::get_primeiro() const {
	return LEs.get_primeiro();
}

Listas::Lista<Entidades::Entidade>::Iterador Listas::ListaEntidades::inicio() const
{
	return LEs.get_primeiro();
}

Listas::Lista<Entidades::Entidade>::Iterador Listas::ListaEntidades::fim() const
{
	return LEs.get_final_vetor();
}