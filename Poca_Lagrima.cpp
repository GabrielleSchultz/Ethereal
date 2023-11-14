#include "Poca_Lagrima.h"

Entidades::Obstaculos::Poca_Lagrimas::Poca_Lagrimas(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id),
slowdown (0.25f)
{
}

Entidades::Obstaculos::Poca_Lagrimas::~Poca_Lagrimas()
{
}

void Entidades::Obstaculos::Poca_Lagrimas::obstacular(Entidades::Personagens::Jogador* p)
{
	p->setAtrito(p->getAtrito() * (1 + slowdown));
}

void Entidades::Obstaculos::Poca_Lagrimas::update(float dt)
{
	desenhar();
}


void Entidades::Obstaculos::Poca_Lagrimas::salvar(std::ostringstream* entrada)
{
}
