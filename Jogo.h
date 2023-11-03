#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"

#include "Jogador.h"

//classe principal

class Jogo {

private:
	std::string nome;
	Gerenciadores::Grafico* pGerenciadorGrafico;
	Gerenciadores::Eventos* pGerenciadorEventos;
	sf::Clock clock;
	float deltaTime;
	float dt_multiplier; //constancia para diferentes framerates

	//teste
	Entidades::Personagens::Jogador* teste;


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