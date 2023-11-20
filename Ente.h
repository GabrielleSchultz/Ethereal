#pragma once
#include "Gerenciador_Grafico.h"

class Ente {

protected:
	const int _id;
	static int cont_id;	
	Gerenciadores::Grafico* pGerenciadorGrafico;

public:
	Ente();
	virtual ~Ente();
	virtual void executar(float dt) = 0;
	virtual void desenhar(){}
	virtual void salvar(std::ostringstream* entrada) = 0;
};