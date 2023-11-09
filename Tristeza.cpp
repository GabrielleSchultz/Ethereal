#include "Tristeza.h"

Entidades::Personagens::Tristeza::Tristeza(int nv, int mal, const char* texturePath, ID id):
Inimigo(nv, mal, texturePath, id)
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
	lancar_projetil();
	//projeteis.executar(dt);
	Listas::Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	for (it = projeteis.get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		aux = it.operator*();
		aux->update(dt);
		if (static_cast<Projetil*>(aux)->getColidiu())
			projeteis.remover(aux);
	}
	desenhar();
}

void Entidades::Personagens::Tristeza::lancar_projetil()
{
	Entidades::Projetil* projetil;
	projetil = new Entidades::Projetil("Assets/Sprites/projetil0.png", 10);
	projetil->setAtirador(this);
	projetil->setDirection(0, 1);
	projetil->setPosition(position.x, position.y);
	projeteis.incluir(projetil);
}