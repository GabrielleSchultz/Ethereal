#include "Plataforma.h"

Entidades::Obstaculos::Plataforma::Plataforma(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id),
forca_normal(0)
{
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::obstacular(Entidades::Personagens::Jogador* p)
{
	p->setPosition(p->getPosition().x, (p->getPosition().y) + forca_normal);
}

void Entidades::Obstaculos::Plataforma::update(float dt)
{
	//nao se afeta pela gravidade
	position.y -= forca_normal;
	desenhar();
}

void Entidades::Obstaculos::Plataforma::salvar(std::ostringstream* entrada)
{
}
