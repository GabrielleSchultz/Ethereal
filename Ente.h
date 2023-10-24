#pragma once

class Ente {

protected:
	const int id;
	static int cont_id;	

public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	void desenhar();
};