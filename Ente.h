#pragma once
#include "Gerenciador_Grafico.h"

class Ente {

protected:
	const int id;
	static int cont_id;	
	Gerenciadores::Grafico* pGerenciadorGrafico;
	sf::Texture textura;
	sf::RectangleShape corpo; //corpo dos nossos entes


public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	void desenhar(); //desenhar

};