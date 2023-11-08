#include "ControleJogador.h"
#include "Jogador.h"

Controle::ControleJogador::ControleJogador(Entidades::Personagens::Jogador* pJog)
{
	setKeyCommands("W", "D", "A", "S");
}

void Controle::ControleJogador::notifyKeyPressed(std::string key)
{
	if (pJogador) {
		if (key == esquerda)
		{
			Math::Vector2Df resultante (-1.f, 0.f);
			pJogador->setDirection(pJogador->getDirection() + resultante);
		}
		
		if (key == direita)
		{
			Math::Vector2Df resultante(-1.f, 0.f);
			pJogador->setDirection(pJogador->getDirection() - resultante);
		}
	}
	else
		std::cout << "Controle::ControleJogador -> ponteiro nulo" << std::endl;

}

void Controle::ControleJogador::notifyKeyReleased(std::string key)
{
	if (pJogador) {
		if (key == esquerda || key == direita)
			pJogador->setDirection(Math::Vector2Df(0.f, 0.f));
	}
	else
		std::cout << "Controle::ControleJogador -> ponteiro nulo" << std::endl;
}

void Controle::ControleJogador::setJogador(Entidades::Personagens::Jogador* jogador)
{
	pGerenciadorInput->adicionar_observer(this);
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
