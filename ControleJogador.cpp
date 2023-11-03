#include "ControleJogador.h"
#include "Jogador.h"

Controle::ControleJogador::ControleJogador(Entidades::Personagens::Jogador* pJog)
{
	setKeyCommands("up", "down", "right", "left");
}

void Controle::ControleJogador::notifyKeyPressed(std::string key)
{
	
}

void Controle::ControleJogador::notifKeyRelease(std::string key)
{
}

void Controle::ControleJogador::setJogador(Entidades::Personagens::Jogador* jogador)
{
	pJogador = jogador;
}

void Controle::ControleJogador::setKeyCommands(std::string jump, std::string right, std::string left, std::string attack)
{
	pular = jump;
	esquerda = left;
	direita = right;
	ataque = attack;
}

void Controle::ControleJogador::setReviveCommand(std::string revive)
{
	
}
