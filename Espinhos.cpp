#include "Espinhos.h"

Entidades::Obstaculos::Espinhos::Espinhos(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id)
{
	danoso = true;
	executar();
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}

void Entidades::Obstaculos::Espinhos::obstacular(Entidades::Personagens::Jogador* p)
{
}

void Entidades::Obstaculos::Espinhos::executar()
{
}

void Entidades::Obstaculos::Espinhos::salvar()
{
}
