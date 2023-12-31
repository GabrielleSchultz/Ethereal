#include "Espinhos.h"

#define IMPACTO_HORIZONTAL 5.f
#define IMPACTO_VERTICAL 100.f

Entidades::Obstaculos::Espinhos::Espinhos(Math::Vector2Df posicao, const char* texture, ID id) :
Obstaculo (posicao, texture, id),
dano (10)
{
	danoso = true;
}

Entidades::Obstaculos::Espinhos::~Espinhos()
{
}

void Entidades::Obstaculos::Espinhos::obstacular(Entidades::Personagens::Jogador* p)
{
	dano = p->getMaxVidas();
	if (p->getNumJogadores() == 2)
		dano = (dano / 2);
	espetar(p);
}

void Entidades::Obstaculos::Espinhos::espetar(Entidades::Personagens::Jogador* p)
{
	p->setNumVidas(p->getNumVidas() - dano);
	if (p->getNumVidas() > 0) {
		Math::Vector2Df impacto(IMPACTO_HORIZONTAL, IMPACTO_VERTICAL);
		p->setPosition(p->getPosition() - impacto);
	}
}

void Entidades::Obstaculos::Espinhos::update(float dt)
{
	desenhar();
}

void Entidades::Obstaculos::Espinhos::salvar(nlohmann::ordered_json& entrada)
{
	salvarEntidade(entrada);
}

void Entidades::Obstaculos::Espinhos::carregar(nlohmann::ordered_json& saida)
{
	carregarDadosEntidade(saida);
}

