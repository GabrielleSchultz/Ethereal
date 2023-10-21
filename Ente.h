#pragma once

//#include "Gerenciador_Grafico.h"
//#include "Figura.h"

class Ente {

protected:
	const int id;
	static int cont_id;
//	static Gerenciador_Grafico* pGG;
//	Figura* pFig;

public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	void desenhar();
};

int Ente::cont_id(0);
