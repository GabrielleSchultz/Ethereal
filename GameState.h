#pragma once
#include "Estado.h"
#include "Fase.h"
#include "Texto.h"

//referencia do código: livro SFML Game Development - Arthur Moreira, Jan Haller

namespace Estados {

	class GameState : public Estado
	{
	private:
		Fases::Fase* pFase;
		Estados::Menus::ElementosGraficos::Texto pontuacao;
	public:
		GameState(int num_fase = 1);
		~GameState();
		void executar(float dt);
		void salvar();
	};

}