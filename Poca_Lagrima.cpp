#include "Poca_Lagrima.h"

Entidades::Obstaculos::Poca_Lagrimas::Poca_Lagrimas(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id)
{
}

Entidades::Obstaculos::Poca_Lagrimas::~Poca_Lagrimas()
{
}

void Entidades::Obstaculos::Poca_Lagrimas::obstacular(Entidades::Personagens::Jogador* p)
{
	p->setAtrito(p->getAtrito() * 1.25f);
}

void Entidades::Obstaculos::Poca_Lagrimas::update(float dt)
{
}


void Entidades::Obstaculos::Poca_Lagrimas::salvar(std::ostringstream* entrada)
{
}
