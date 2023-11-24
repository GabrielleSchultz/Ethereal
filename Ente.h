#pragma once
#include "Gerenciador_Grafico.h"
#include "json.h"

class Ente {
protected:
	const int _id;
	static int cont_id;	
	static Gerenciadores::Grafico* pGerenciadorGrafico;

public:
	Ente();
	virtual ~Ente();
	virtual void executar(float dt) = 0;
	virtual void desenhar() {}
	virtual void update(float dt){}
	virtual void salvar(nlohmann::ordered_json& entrada) = 0;
};