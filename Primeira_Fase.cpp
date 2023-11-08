#include "Primeira_Fase.h"
#include "Raiva.h"
#include "Tristeza.h"
#include "Vinganca.h"

Fases::Primeira_Fase::Primeira_Fase()
{
}

Fases::Primeira_Fase::~Primeira_Fase()
{
}

void Fases::Primeira_Fase::executar(float dt)
{
	pixi->update(dt);
	//pixi->executar(dt);
	if (bity)
		bity->update(dt);
		//bity->executar(dt);

	Listas::Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	for (it = inimigos.get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		aux = it.operator*();
		aux->update(dt);
		//aux->executar(dt);
		if (aux->getId() == Entidades::ID::inimigo_raiva) {
			static_cast<Entidades::Personagens::Raiva*>(aux)->perseguir(pixi);
			if (bity)
				static_cast<Entidades::Personagens::Raiva*>(aux)->perseguir(bity);
		}
	}
}

void Fases::Primeira_Fase::desenhar()
{
}

void Fases::Primeira_Fase::salvar(std::ostringstream* entrada)
{
}

void Fases::Primeira_Fase::criar_inimigos()
{
	Entidades::Personagens::Raiva* raivinha = nullptr;
	for (int i = 0; i < 3; i++) {
		raivinha = new Entidades::Personagens::Raiva();
		raivinha->setPosition((float)700 + 64 * i, 450);
		inimigos.incluir(raivinha);
	}

	Entidades::Personagens::Tristeza* sadness = nullptr;
	for (int i = 0; i < 3; i++) {
		sadness = new Entidades::Personagens::Tristeza();
		sadness->setPosition((float)450 + 64 * i, 200);
		inimigos.incluir(sadness);
	}

	Entidades::Personagens::Vinganca* boss = new Entidades::Personagens::Vinganca();
	boss->setPosition(150, 600);
	inimigos.incluir(boss);
}

void Fases::Primeira_Fase::criar_obstaculos()
{
}

void Fases::Primeira_Fase::criar_cenario(std::string file_path)
{
}