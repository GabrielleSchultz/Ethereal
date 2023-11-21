#include "GameState.h"

Estados::GameState::GameState(Fases::Fase* f):
Estado(),
pFase(f)
{

}

Estados::GameState::~GameState() {
	pFase = nullptr;
}