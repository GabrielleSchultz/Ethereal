#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisoes.h"
#include "Segunda_Fase.h"
//#include "Primeira_Fase.h"

#include "Raiva.h"
namespace Entidades {
	namespace Personagens {
		class Tristeza;
		class Vinganca;
	}
}

//classe principal

class Jogo {

private:
	std::string nome;
	Gerenciadores::Grafico* pGerenciadorGrafico;
	Gerenciadores::Eventos* pGerenciadorEventos;
	sf::Clock clock;
	float deltaTime;
	float dt_multiplier; //constancia para diferentes framerates

	Fases::Segunda_Fase pfase;
	//Fases::Primeira_Fase pfase;

public:
	Jogo();
	~Jogo();
	void executar();
	bool running();
	void pollEvents();
	void updateDeltaTime();
	void clear();
	void update();
	void draw();

};