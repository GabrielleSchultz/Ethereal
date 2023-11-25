#pragma once
#include "Controller.h"
#include "Gerenciador_Estados.h"

namespace Entidades {
	namespace Personagens{
		class Jogador;
	}
}

namespace Controle {

	class ControleJogador : public Controller
	{
	private:
		Entidades::Personagens::Jogador* pJogador;

		std::string pular;
		std::string direita;
		std::string esquerda;
		std::string ataque;
		std::string ressucitar;
		std::string pause;

		static Gerenciadores::Gerenciador_Estados* pGE;

	public:

		ControleJogador();
		~ControleJogador() { pJogador = nullptr; }

		void notifyKeyPressed(std::string key);
		void notifyKeyReleased(std::string key);

		void setJogador(Entidades::Personagens::Jogador* jogador);
		void setKeyCommands(std::string jump, std::string right, std::string left, std::string attack, std::string pausar);
		void setReviveCommand(std::string revive); //somente se dois jogadores

		//mudar comandos
		/*
		void setJumpCommand(std::string jump);
		void setMoveRightCommand(std::string right);
		void setMoveLeftCommand(std::string left);
		void setAttackCommand(std::string left);
		*/
	};
}

