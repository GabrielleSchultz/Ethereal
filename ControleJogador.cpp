#include "ControleJogador.h"
#include "Jogador.h"

Gerenciadores::Gerenciador_Estados* Controle::ControleJogador::pGE(Gerenciadores::Gerenciador_Estados::getGerenciadorEstados());

Controle::ControleJogador::ControleJogador() :
	Controller(),
	pJogador(nullptr)
{
	setKeyCommands("W", "D", "A", "S", "space");
}

void Controle::ControleJogador::notifyKeyPressed(std::string key)
{
	if (pJogador) {
		if (key == esquerda)
		{
			Math::Vector2Df resultante(-1.f, 0.f);
			pJogador->setDirection(pJogador->getDirection() + resultante);
			pJogador->setFacingRight(false);
		}

		if (key == direita)
		{
			Math::Vector2Df resultante(-1.f, 0.f);
			pJogador->setDirection(pJogador->getDirection() - resultante);
			pJogador->setFacingRight(true);
		}

		if (key == pular)
		{
			pJogador->pular();
		}

		if (key == ataque) {
			pJogador->atacar();
		}

		if (key == pause) {
			pGE->push(Estados::Tipo::MenuPause);
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

void Controle::ControleJogador::setKeyCommands(std::string jump, std::string right, std::string left, std::string attack, std::string pausar)
{
	pular = jump;
	esquerda = left;
	direita = right;
	ataque = attack;
	pause = pausar;
}

void Controle::ControleJogador::setReviveCommand(std::string revive)
{

}
