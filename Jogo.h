#pragma once
#include <string>
#include "Gerenciador_Grafico.h"

//classe principal

class Jogo {

private:
	std::string nome;
	Gerenciadores::Grafico* pGerenciadorGrafico;
	sf::Event ev;
	sf::Clock clock;
	float deltaTime;
	float dt_multiplier; //constancia para diferentes framerates

	//teste
	sf::RectangleShape teste;
	sf::Vector2f currentVelocity;
	sf::Vector2f direction;
	float maxVel;
	float acceleration;
	float atrito;


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