#pragma once
#include "Gerenciador_Grafico.h"

class Ente {

protected:
	const int id;
	static int cont_id;	
	Gerenciadores::Grafico* pGerenciadorGrafico;

public:
	Ente();
	virtual ~Ente();
	virtual void executar(float dt) = 0;
	virtual void desenhar() = 0;
	virtual void salvar(std::ostringstream* entrada) = 0;
};