#pragma once

#include <iostream>

// código das Listas feito com base nos vídeos do Felipe Barbosa
// e no código passado pelo Peteco

namespace Listas {
	template <class TL> class Lista {
	private:
		template <class TE> class Elemento {
		private:
			Elemento<TE>* proximo;
			TE* info;

		public:
			Elemento();
			~Elemento();
			void setProximo(Elemento<TE>* p);
			void setInfo(TE* i);
			Elemento<TE>* getProximo();
			TE* getInfo();

		};


		Elemento<TL>* primeiro;
		Elemento<TL>* ultimo;
		int tamanho;

	public:
		Lista();
		~Lista();
		const int getTamanho() const;
		void incluir(TL* elemento);
		void remover(TL* elemento);
		void clear();

		class Iterador {
		private:
			Elemento<TL>* atual;
		public:
			Iterador(Elemento<TL>* a = nullptr);
			~Iterador();
			Iterador& operator++() {
				atual = atual->getProximo();
				return *this;
			}
			bool operator==(const Elemento<TL>* outro) const;
			void operator=(const Elemento<TL>* outro);
			TL* operator*();
			Elemento<TL>* get_atual() const;
			Elemento<TL>* get_proximo() const;
		};

		Iterador get_primeiro() const {
			return Iterador(primeiro);
		}
	};
}


/* ELEMENTO */
template <class TL>
template <class TE>
Listas::Lista<TL>::Elemento<TE>::Elemento() : proximo(nullptr), info(nullptr) {

}

template <class TL>
template <class TE>
Listas::Lista<TL>::Elemento<TE>::~Elemento() {
	proximo = nullptr;
	info = nullptr;
}

template <class TL>
template <class TE>
void Listas::Lista<TL>::Elemento<TE>::setProximo(Elemento<TE>* p) {
	if (p) {
		proximo = p;
	}
}

template <class TL>
template <class TE>
void Listas::Lista<TL>::Elemento<TE>::setInfo(TE* i) {
	if (i) {
		info = i;
	}
}

template <class TL>
template <class TE>
Listas::Lista<TL>::Elemento<TE>* Listas::Lista<TL>::Elemento<TE>::getProximo() {
	return proximo;
}

template <class TL>
template <class TE>
TE* Listas::Lista<TL>::Elemento<TE>::getInfo() {
	return info;
}

/* LISTA */
template <class TL>
Listas::Lista<TL>::Lista() {
	primeiro = nullptr;
	ultimo = nullptr;
	tamanho = 0;
}

template <class TL>
Listas::Lista<TL>::~Lista() {
	clear();
}

template <class TL>
const int Listas::Lista<TL>::getTamanho() const {
	return tamanho;
}

template <class TL>
void Listas::Lista<TL>::incluir(TL* elemento) {

	if (!elemento) {
		return;
	}

	Elemento<TL>* aux = new Elemento<TL>;
	aux->setInfo(elemento);

	if (primeiro == nullptr) {
		primeiro = aux;
	}
	else {
		ultimo->setProximo(aux);
	}
	ultimo = aux;
	ultimo->setProximo(nullptr);
	tamanho++;
}

template <class TL>
void Listas::Lista<TL>::remover(TL* elemento) {
	Elemento<TL>* aux = primeiro;
	Elemento<TL>* anterior = primeiro;

	while (aux->getInfo() != elemento) {
		anterior = aux;
		aux = aux->getProximo();
	}

	if (aux == primeiro) {
		primeiro = aux->getProximo();
	}

	else if (aux == ultimo) {
		anterior->setProximo(nullptr);
		ultimo = anterior;
	}

	else {
		anterior->setProximo(aux->getProximo());
	}

	tamanho--;
}

template<class TL>
void Listas::Lista<TL>::clear()
{
	Elemento<TL>* aux = nullptr;
	while (primeiro) {
		aux = primeiro;
		primeiro = primeiro->getProximo();
		if (aux)
			delete aux;
	}
	tamanho = 0;
	primeiro = nullptr;
}

/* ITERADOR */
template <class TL>
Listas::Lista<TL>::Iterador::Iterador(Elemento<TL>* a) :
	atual(a)
{

}

template <class TL>
Listas::Lista<TL>::Iterador::~Iterador()
{
	atual = nullptr;
}

template <class TL>
bool Listas::Lista<TL>::Iterador::operator==(const Elemento<TL>* outro) const
{
	return atual == outro;
}

template <class TL>
void Listas::Lista<TL>::Iterador::operator=(const Elemento<TL>* outro)
{
	atual = outro;
}

template <class TL>
TL* Listas::Lista<TL>::Iterador::operator*()
{
	return atual->getInfo();
}

template <class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::Iterador::get_atual() const
{
	return atual;
}

template <class TL>
Listas::Lista<TL>::Elemento<TL>* Listas::Lista<TL>::Iterador::get_proximo() const
{
	return atual->getProximo();
}