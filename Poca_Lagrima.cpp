#include "Poca_Lagrima.h"

Entidades::Obstaculos::Poca_Lagrimas::Poca_Lagrimas(Math::Vector2Df posicao, const char* texture, ID id) :
	Obstaculo(posicao, texture, id),
	coeficiente_aceleracao(0.25f)
{
}

Entidades::Obstaculos::Poca_Lagrimas::~Poca_Lagrimas()
{
}

void Entidades::Obstaculos::Poca_Lagrimas::obstacular(Entidades::Personagens::Jogador* p)
{
	p->setAtrito(p->getAtrito() * (0.1 + coeficiente_aceleracao));
	p->setPosition(p->getPosition().x, position.y - tamanho.y / 2 - p->getTamanho().y / 2);
}

void Entidades::Obstaculos::Poca_Lagrimas::update(float dt)
{
	desenhar();
}


void Entidades::Obstaculos::Poca_Lagrimas::salvar(std::ostringstream* entrada)
{
}
