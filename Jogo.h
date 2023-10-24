#pragma once
#include <string>
#include "Gerenciador_Grafico.h"

class Jogo {

private:
	std::string nome;
	Gerenciadores::Grafico* pGerenciadorGrafico;

public:
	Jogo();
	~Jogo();
	void executar();
	void inicializaEntidades();

};