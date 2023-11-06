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
	desenhar();
}
