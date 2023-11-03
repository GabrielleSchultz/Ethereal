#include "Poca_Lagrima.h"

Entidades::Obstaculos::Poca_Lagrimas::Poca_Lagrimas(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id)
{
	executar();
}

Entidades::Obstaculos::Poca_Lagrimas::~Poca_Lagrimas()
{
}

void Entidades::Obstaculos::Poca_Lagrimas::obstacular(Entidades::Personagens::Jogador* p)
{
}

void Entidades::Obstaculos::Poca_Lagrimas::executar()
{
}

void Entidades::Obstaculos::Poca_Lagrimas::salvar()
{
}
