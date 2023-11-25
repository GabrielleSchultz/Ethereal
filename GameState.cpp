#include "GameState.h"

#include "Primeira_Fase.h"
#include "Segunda_Fase.h"

Estados::GameState::GameState(int num_fase) :
	Estado(),
	pFase(nullptr)
{
	if (num_fase == 1) {
		pFase = new Fases::Primeira_Fase();
		pFase->criar_cenario("Mapas/Fase1.txt");
	}
	else if (num_fase == 2) {
		pFase = new Fases::Segunda_Fase();
		pFase->criar_cenario("Mapas/Fase2.txt");
	}
	pFase->criar_obstaculos();
	pFase->criar_inimigos();
	// else if num_fase == 3 --> recuperar jogo talvez ???
}

Estados::GameState::~GameState()
{
	pFase = nullptr;
}

void Estados::GameState::executar(float dt) {
	pFase->executar(dt);
	pFase->gerenciar_colisoes();
}