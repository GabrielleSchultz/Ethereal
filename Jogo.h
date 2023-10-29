#pragma once
#include <string>
#include "Gerenciador_Grafico.h"

class Jogo {

private:
	std::string nome;
	Gerenciadores::Grafico* pGerenciadorGrafico;
	sf::Event ev;

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