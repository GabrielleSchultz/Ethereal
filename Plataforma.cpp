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
	p->setPosition(p->getPosition().x, position.y - tamanho.y / 2 - p->getTamanho().y / 2);
}

void Entidades::Obstaculos::Plataforma::update(float dt)
{
	//nao se afeta pela gravidade
	position.y -= forca_normal;
	desenhar();
}

void Entidades::Obstaculos::Plataforma::salvar(nlohmann::ordered_json& entrada)
{
}

void Entidades::Obstaculos::Plataforma::carregar(nlohmann::ordered_json& saida)
{
}

