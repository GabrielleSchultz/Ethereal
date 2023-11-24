#pragma once
#include "Estado.h"
#include "Fase.h"

namespace Estados {

	class GameState : public Estado
	{
	private:
		Fases::Fase* pFase;
	public:
		GameState(int num_fase = 1);
		~GameState();
		void executar(float dt);
	};

}