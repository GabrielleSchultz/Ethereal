#include "Estado.h"
#include "Gerenciador_Estados.h"

Gerenciadores::Gerenciador_Estados* Estados::Estado::pGE(Gerenciadores::Gerenciador_Estados::getGerenciadorEstados());
bool Estados::Estado::multiplayer(true);
unsigned int Estados::Estado::pontuacao_jogo(0);

Estados::Estado::Estado():
	ativo(true)
{
}

Estados::Estado::~Estado()
{
}

void Estados::Estado::request_push(Estados::Tipo id_estado)
{
	pGE->push(id_estado);
}

void Estados::Estado::request_pop()
{
	pGE->pop();
}

void Estados::Estado::request_clear()
{
	pGE->clear();
}

void Estados::Estado::setAtivo(bool b)
{
	ativo = b;
}

bool Estados::Estado::getAtivo()const
{
	return ativo;
}

void Estados::Estado::setMultiplayer(const bool b)
{
	multiplayer = b;
}

bool Estados::Estado::getMultiplayer()
{
	return multiplayer;
}

void Estados::Estado::setPontuacao(const unsigned int pontos)
{
	pontuacao_jogo = pontos;
}

unsigned int Estados::Estado::getPontuacao()
{
	return pontuacao_jogo;
}