#include "ControleJogador.h"


Controle::ControleJogador::ControleJogador(Entidades::Personagens::Jogador* pJog)
{
	if (pJog->isPlayer1())
		setKeyCommands("up", "down", "right", "left");
	else
		setKeyCommands("w", "s", "d", "a");
}

void Controle::ControleJogador::notifyKeyPressed(std::string key)
{
	if(key == ressucitar){}
	//pJogador->tentarRessucitar();
	else
	{
		Math::Vector2Df movimento (0,0);
		if (key == esquerda)
		movimento.x--;
		//	pJogador->setDirection(movimento);
		if (key == direita)
		movimento.x++;
		// pJogador->setDirection
		if (key == pular)
		movimento.y++;
		// pJogador->jump();
		if (key == ataque){}
	}
		
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
