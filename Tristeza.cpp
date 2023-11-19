#include "Tristeza.h"

#define FREQUENCIA_LANCAMENTO 1000

Entidades::Personagens::Tristeza::Tristeza(int nv, int mal, const char* texturePath, ID id) :
	Inimigo(nv, mal, texturePath, id),
	lancamento(0),
	projeteis()
	//projetil(nullptr)
{
}

Entidades::Personagens::Tristeza::~Tristeza()
{
}

void Entidades::Personagens::Tristeza::executar()
{
}

void Entidades::Personagens::Tristeza::danificar(Jogador* p)
{
}

void Entidades::Personagens::Tristeza::salvar(std::ostringstream* entrada)
{
}

void Entidades::Personagens::Tristeza::update(float dt)
{

	if (lancamento == FREQUENCIA_LANCAMENTO) {
		lancar_projetil();
		lancamento = 0;
	}
	lancamento++;
	
	/*if (projetil)
		projetil->update(dt);*/
	//projeteis.executar(dt);
	Listas::Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	int i = 0;
	//for (it = projeteis.get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
	for (it = projeteis.get_primeiro(), i = 0; i < projeteis.getTamanho(); it.operator++(), i++) {
		aux = it.operator*();
		if(aux != nullptr){
			aux->update(dt);
		}
	}
	desenhar();
}

void Entidades::Personagens::Tristeza::lancar_projetil()
{
	/*if (projetil) {
		delete projetil;
	}*/
	Entidades::Projetil* projetil = nullptr;
	projetil = new Entidades::Projetil("Assets/Sprites/teardrop_projectile_cortado.png", 1, 2);
	projetil->setAtirador(this);
	projetil->setDirection(0, 1);
	projetil->setPosition(position.x, position.y);
	projeteis.incluir(projetil);
}

void Entidades::Personagens::Tristeza::colidir()
{
}

Listas::ListaEntidades* Entidades::Personagens::Tristeza::getProjeteis()
{
	return &projeteis;
}

/*Entidades::Projetil* Entidades::Personagens::Tristeza::getProjetil() {
	return projetil;
}*/
