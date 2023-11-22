#include "GameState.h"

Estados::GameState::GameState():
	Estado(),
	pFase(nullptr)
{
}

Estados::GameState::~GameState()
{
	pFase = nullptr;
}
