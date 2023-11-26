#include "GameState.h"

#include "Primeira_Fase.h"
#include "Segunda_Fase.h"

Estados::GameState::GameState(int num_fase) :
	Estado(),
	pFase(nullptr),
	pontuacao(),
	carrega_fase(0)
{
	pontuacao.setTamanho(25);
	pontuacao.setPosicao(Math::Vector2Df(77, 77));
	if (num_fase == 1) {
		pFase = new Fases::Primeira_Fase();
		pFase->criar_cenario("Mapas/Fase1.txt");
		pFase->criar_obstaculos();
		pFase->criar_inimigos();
	}
	else if (num_fase == 2) {
		pFase = new Fases::Segunda_Fase();
		pFase->criar_cenario("Mapas/Fase2.txt"); 
		pFase->criar_obstaculos();
		pFase->criar_inimigos();
	}
	else if (num_fase == 3) {

		using namespace nlohmann;
		std::ifstream faseStream("../Ethereal/Data/fase_data.json");
		if (!faseStream)
			throw std::runtime_error("Error loading stage data!");
		ordered_json faseData = ordered_json::parse(faseStream);
		carrega_fase = (faseData["num_fase"].template get<int>());
		faseStream.close();

		if(carrega_fase == 1)
		{
			pFase = new Fases::Primeira_Fase();
			pFase->criar_cenario("Mapas/Fase1.txt");
			pFase->criar_obstaculos();
			//pFase->criar_inimigos();
			pFase->carregar();
		}

		else if (carrega_fase == 2) {
			pFase = new Fases::Segunda_Fase();
			pFase->criar_cenario("Mapas/Fase2.txt");
			pFase->criar_obstaculos();
			//pFase->criar_inimigos();
			pFase->carregar();
		}
	}
}

Estados::GameState::~GameState()
{
	pFase = nullptr;
}

void Estados::GameState::executar(float dt) {

	if (!pFase->getfim_de_fase()) {
		//std::cout << "executando" << std::endl;
		pFase->executar(dt);
		//pFase->gerenciar_colisoes();   COLOQUEI DENTRO DO EXECUTAR FASE
		pontuacao.setTexto(std::to_string(Entidades::Personagens::Jogador::getPontos()));
		pontuacao.desenhar();
		//pFase->salvarJogadores();
	}
	else if (pFase->getproxima_fase()) {
		//std::cout << "CRIOU SEGUNDA FASE" << std::endl;
		pFase = new Fases::Segunda_Fase();
		pFase->criar_cenario("Mapas/Fase2.txt");
		pFase->criar_obstaculos();
		pFase->criar_inimigos();
	}
	else {
		pontuacao_jogo = pFase->getPontuacaoJogadores();
		request_pop();
		request_push(Estados::Tipo::Gameover);
	}
}

void Estados::GameState::salvar_jogo()
{

	if (Estados::GameState::pFase)
	{
		nlohmann::ordered_json ethereal;
		pFase->salvar(ethereal);
	}
}