#include "Primeira_Fase.h"
#include "Raiva.h"
#include "Tristeza.h"
#include "Plataforma.h"
#include <fstream>
#include <iostream>

Fases::Primeira_Fase::Primeira_Fase():
	Fase()
{
}

Fases::Primeira_Fase::~Primeira_Fase()
{
}

void Fases::Primeira_Fase::executar(float dt)
{
	pGerenciadorGrafico->desenhar("Assets/Backgrounds/Stage1_full_background.png", Math::Vector2Df(0, 0));

	Listas::Lista<Entidades::Entidade>::Iterador jog;
	Entidades::Entidade* jogador = nullptr;

	int j = 0, i = 0, o = 0;
	for (jog = jogadores.get_primeiro(), j = 0; j < jogadores.getTamanho(); jog.operator++(), j++) {
		jogador = jog.operator*();
		jogador->update(dt);
		//jogador->executar(dt);


		Listas::Lista<Entidades::Entidade>::Iterador it;
		Entidades::Entidade* aux = nullptr;
		for (it = inimigos.get_primeiro(), i = 0; i < inimigos.getTamanho(); it.operator++(), i++) {
			aux = it.operator*();
			aux->update(dt);
			//aux->executar(dt);
			if (static_cast<Entidades::Personagens::Personagem*>(aux)->getNumVidas() <= 0) {
				inimigos.remover(aux);
				delete aux;
			}
			if (aux->getId() == Entidades::ID::inimigo_raiva) {
				static_cast<Entidades::Personagens::Raiva*>(aux)->perseguir(static_cast<Entidades::Personagens::Jogador*>(jogador));
			}
		}

		for (it = obstaculos.get_primeiro(), o = 0; o < obstaculos.getTamanho(); it.operator++(), o++) {
			aux = it.operator*();
			aux->update(dt);
			static_cast<Entidades::Obstaculos::Plataforma*>(aux)->obstacular(static_cast<Entidades::Personagens::Jogador*>(jogador));
		}
	}

	pGerenciadorGrafico->desenharEnte("Assets/Backgrounds/Stars Small_1.png", Math::Vector2Df(0, 0));
}

void Fases::Primeira_Fase::desenhar()
{
}

void Fases::Primeira_Fase::salvar(std::ostringstream* entrada)
{
}

void Fases::Primeira_Fase::criar_inimigos()
{
	srand(time(NULL));

	Entidades::Personagens::Raiva* raivinha = nullptr;
	for (int i = 0; i < rand() % 2 + 3; i++) {
		raivinha = new Entidades::Personagens::Raiva();
		if(raivinha)
		{
			raivinha->setPosition((float)700 + 64 * i, 450);
			inimigos.incluir(raivinha);
		}
	}

	Entidades::Personagens::Tristeza* sadness = nullptr;
	for (int i = 0; i < rand() % 2 + 3; i++) {
		sadness = new Entidades::Personagens::Tristeza();
		if(sadness)
		{
			sadness->setPosition((float)450 + 64 * i, 200);
			inimigos.incluir(sadness);
		}
	}
}

void Fases::Primeira_Fase::criar_obstaculos()
{
}

void Fases::Primeira_Fase::criar_cenario(std::string file_path)
{
	std::ifstream arq(file_path);
	if (!arq)
	{
		std::cout << "N�o foi poss�vel abrir arquivo de cen�rio" << std::endl;
		exit(1);
	}
	std::string linha;
	Entidades::Entidade* aux = nullptr;

	int i = 0, j = 0;
	for (i = 0; std::getline(arq, linha); i++, j = 0)
	{
		for (char simbolo : linha)
		{
			switch (simbolo)
			{
			case '#':
				//std::cout << "Criou plataforma" << j * 32 << i * 32 << std::endl;
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Plataforma(Math::Vector2Df(j * 32.f, i * 32.f), "Assets/Sprites/middle_ground_sprite.png"));
				if (aux) 
					obstaculos.incluir(aux);
					break;
			case 'P':
				criar_jogador('P');
				//pixi->setPosition((float)j * 64, (float)i * 64);
				//std::cout << "Criou o jogador em " << j * 10.0 << i * 10.0 << std::endl;

				break;
			case 'B':
				criar_jogador('B');
				//bity->setPosition((float)j * 64, (float)i * 64);
				//std::cout << "Criou o jogador em " << j * 10.0 << i * 10.0 << std::endl;

				break;
			case '*':
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Plataforma(Math::Vector2Df(j * 32.f, i * 32.f), "Assets/Sprites/top_ground_sprite.png"));
				//std::cout << "Criou plataforma" << j * 32 << i * 32 << std::endl;
				if (aux)
					obstaculos.incluir(aux);

				break;
			default:
				break;
				}
				j++;
			}
		}

		arq.close();
}
