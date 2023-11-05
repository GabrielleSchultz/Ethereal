#pragma once
#include "Gerenciador_Grafico.h"
#include "Gerenciador_Eventos.h"
#include "Gerenciador_Colisoes.h"

#include "Raiva.h"
namespace Entidades {
	namespace Personagens {
		class Tristeza;
		class Vinganca;
	}
}

//classe principal

class Jogo {

private:
	std::string nome;
	Gerenciadores::Grafico* pGerenciadorGrafico;
	Gerenciadores::Eventos* pGerenciadorEventos;
	Gerenciadores::Colisoes* pGerenciadorColisoes;
	sf::Clock clock;
	float deltaTime;
	float dt_multiplier; //constancia para diferentes framerates

	//teste
	Entidades::Personagens::Jogador* teste;
	Entidades::Personagens::Raiva* raivinha;
	Entidades::Personagens::Raiva* raivinha2;
	Entidades::Personagens::Tristeza* sadness;
	Entidades::Personagens::Vinganca* boss;

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