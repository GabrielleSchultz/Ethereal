#include "Plataforma.h"

Entidades::Obstaculos::Plataforma::Plataforma(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id)
{
	executar();
}

Entidades::Obstaculos::Plataforma::~Plataforma()
{
}

void Entidades::Obstaculos::Plataforma::obstacular(Entidades::Personagens::Jogador* p)
{
}

void Entidades::Obstaculos::Plataforma::executar()
{
}

void Entidades::Obstaculos::Plataforma::salvar()
{
}
