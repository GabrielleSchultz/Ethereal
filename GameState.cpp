#include "GameState.h"

#include "Primeira_Fase.h"
#include "Segunda_Fase.h"

Estados::GameState::GameState(int num_fase) :
	Estado(),
	pFase(nullptr),
	pontuacao()
{
	pontuacao.setTamanho(25);
	pontuacao.setPosicao(Math::Vector2Df(77, 77));
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

	if (!pFase->getfim_de_fase()) {
		pFase->executar(dt);
		pFase->gerenciar_colisoes();
		pontuacao.setTexto(std::to_string(Entidades::Personagens::Jogador::getPontos()));
		pontuacao.desenhar();
	}
	else if (pFase->getproxima_fase()) {
		std::cout << "CRIOU SEGUNDA FASE" << std::endl;
		pFase = new Fases::Segunda_Fase();
		pFase->criar_cenario("Mapas/Fase2.txt");
		pFase->criar_obstaculos();
		pFase->criar_inimigos();
	}
	else {
		request_pop();
		request_push(Estados::Tipo::Gameover);
	}
}