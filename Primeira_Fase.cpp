#include "Primeira_Fase.h"
#include "Raiva.h"
#include "Tristeza.h"
#include "Vinganca.h"
#include "Plataforma.h"
#include <fstream>
#include <iostream>

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

	for (it = obstaculos.get_primeiro(); (!it.operator==(nullptr)); it.operator++()) {
		aux = it.operator*();
		aux->update(dt);
		static_cast<Entidades::Obstaculos::Plataforma*>(aux)->obstacular(pixi);
		static_cast<Entidades::Obstaculos::Plataforma*>(aux)->obstacular(bity);
		//aux->executar(dt);
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
		if(raivinha)
		{
			raivinha->setPosition((float)700 + 64 * i, 450);
			inimigos.incluir(raivinha);
		}
	}

	Entidades::Personagens::Tristeza* sadness = nullptr;
	for (int i = 0; i < 3; i++) {
		sadness = new Entidades::Personagens::Tristeza();
		if(sadness)
		{
			sadness->setPosition((float)450 + 64 * i, 200);
			inimigos.incluir(sadness);
		}
	}

	/*Entidades::Personagens::Vinganca* boss = new Entidades::Personagens::Vinganca();
	boss->setPosition(150, 600);
	inimigos.incluir(boss);*/
}

void Fases::Primeira_Fase::criar_obstaculos()
{
	Entidades::Obstaculos::Plataforma* p = nullptr;
	for (int i = 0; i < 60; i++) {
		p = new Entidades::Obstaculos::Plataforma(Math::Vector2Df(450 + 64 * i, 250), "Assets/Sprites/top_ground_sprite.png");
		std::cout << "Criou chão" << Math::Vector2Df(450 + 64 * i, 250).x << Math::Vector2Df(450 + 64 * i, 250).y << std::endl;
		if (p) {
			obstaculos.incluir(p);
		}
	}
}

void Fases::Primeira_Fase::criar_cenario(std::string file_path)
{
	std::ifstream arq(file_path);
	if (!arq ) {
		std::cout << "Não foi possível abrir arquivo de cenário" << std::endl;
		exit(1);
	}
	std::string linha;
	Entidades::Entidade* aux = nullptr;

	int i = 0, j = 0;
	for (i = 0; std::getline(arq, linha); i++, j = 0) {
		for (char simbolo : linha) {
			switch (simbolo) {
			case '#': {
				std::cout << "Criou plataforma" << j * 10.0 << i * 10.0 << std::endl;
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Plataforma(Math::Vector2Df(j * 10.0, i * 10.0), "Assets/Sprites/middle_ground_sprite.png"));
				if(aux)
					obstaculos.incluir(aux);
			}break;
			case 'P': {
				criar_jogador('P');
				pixi->setPosition(j * 10.0, i * 10.0);
				std::cout << "Criou o jogador em " << j * 10.0 << i * 10.0 << std::endl;
			}break;
			case 'B': {
				criar_jogador('B');
				bity->setPosition(j * 10.0, i * 10.0);
				std::cout << "Criou o jogador em " << j * 10.0 << i * 10.0 << std::endl;
			}break;
			case '*': {
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Plataforma(Math::Vector2Df(j * 10.0, i * 10.0), "Assets/Sprites/top_ground_sprite.png"));
				std::cout << "Criou plataforma" << j * 10.0 << i * 10.0 << std::endl;
				if (aux)
					obstaculos.incluir(aux);
			}break;
			}
			j++;
		}
	}

	arq.close();
}