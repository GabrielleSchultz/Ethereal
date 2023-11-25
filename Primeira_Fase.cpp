#include "Primeira_Fase.h"
#include "Raiva.h"
#include "Tristeza.h"
#include "Plataforma.h"
#include "Espinhos.h"
#include <fstream>
#include <iostream>

Fases::Primeira_Fase::Primeira_Fase() :
	Fase(),
	max_raiva(3), max_tristeza(2)
{
	pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stage1_full_background.png");
	pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stars Small_1.png");
}

Fases::Primeira_Fase::~Primeira_Fase()
{
}

void Fases::Primeira_Fase::executar(float dt)
{
	if (fim_de_fase) {
		if (jogadores.getTamanho() != 0)
			proxima_fase = true;
	}
	else {
		pGerenciadorGrafico->desenhar("Assets/Backgrounds/Stage1_full_background.png", Math::Vector2Df(0, 0));

		Listas::Lista<Entidades::Entidade>::Iterador jog;
		Entidades::Entidade* jogador = nullptr;

		int j = 0, i = 0, o = 0;
		for (jog = jogadores.get_primeiro(), j = 0; j < jogadores.getTamanho(); jog.operator++(), j++) {
			jogador = jog.operator*();
			//jogador->update(dt);
			jogador->executar(dt);

			Listas::Lista<Entidades::Entidade>::Iterador it;
			Entidades::Entidade* aux = nullptr;
			for (it = inimigos.get_primeiro(), i = 0; i < inimigos.getTamanho(); it.operator++(), i++) {
				aux = it.operator*();
				//aux->update(dt);
				aux->executar(dt);
				if (!static_cast<Entidades::Personagens::Personagem*>(aux)->getVivo()) {
					//inimigos.remover(aux);
					//delete aux;
					static_cast<Entidades::Personagens::Jogador*>(jogador)->operator++(100);
				}
				else if (aux->getId() == Entidades::ID::inimigo_raiva) {
					static_cast<Entidades::Personagens::Raiva*>(aux)->perseguir(static_cast<Entidades::Personagens::Jogador*>(jogador));
				}
			}

			for (it = obstaculos.get_primeiro(), o = 0; o < obstaculos.getTamanho(); it.operator++(), o++) {
				aux = it.operator*();
				aux->update(dt);
			}

			/*if (!static_cast<Entidades::Personagens::Personagem*>(jogador)->getVivo()) {
				jogadores.remover(jogador);
				delete jogador;
			}*/
		}
		pGerenciadorGrafico->desenharEnte("Assets/Backgrounds/Stars Small_1.png", Math::Vector2Df(0, 0));

		remover_sem_vida(&inimigos);
		remover_sem_vida(&jogadores);
	}
}

void Fases::Primeira_Fase::salvar(std::ostringstream* entrada)
{
}

void Fases::Primeira_Fase::criar_inimigos()
{
	srand(time(NULL));

	Entidades::Personagens::Raiva* raivinha = nullptr;
	for (int i = 0; i < rand() % max_raiva + 3; i++) {
		raivinha = new Entidades::Personagens::Raiva();
		if (raivinha)
		{
			raivinha->setPosition((float)700 + 64 * i, 200);
			inimigos.incluir(raivinha);
		}
	}

	Entidades::Personagens::Tristeza* sadness = nullptr;
	for (int i = 0; i < rand() % max_tristeza + 3; i++) {
		sadness = new Entidades::Personagens::Tristeza();
		if (sadness)
		{
			sadness->setPosition((float)450 + 64 * i, 100 * (rand() % 2 + 2));
			sadness->setMovimentacao((float)450 + 64 * i);
			inimigos.incluir(sadness);
		}
	}
}

void Fases::Primeira_Fase::criar_obstaculos()
{
	srand(time(NULL));
	int i = 0, x = 12;
	const int qtd_espinhos = rand() % 3 + 3;

	Entidades::Obstaculos::Espinhos* espinho = nullptr;
	for (i = 0; i < qtd_espinhos; i++, x++) {
		espinho = new Entidades::Obstaculos::Espinhos(Math::Vector2Df(x * 32.f + 16.f, 654.f));
		if (espinho)
			obstaculos.incluir(espinho);
	}

	Entidades::Obstaculos::Plataforma* plataforma_cima = nullptr;
	Entidades::Obstaculos::Plataforma* plataforma_baixo = nullptr;
	for (i = 0; i < 5 - qtd_espinhos; i++, x++) {
		plataforma_cima = new Entidades::Obstaculos::Plataforma(Math::Vector2Df(x * 32.f + 16.f, 624.f), "Assets/Sprites/middle_ground_sprite.png");
		plataforma_baixo = new Entidades::Obstaculos::Plataforma(Math::Vector2Df(x * 32.f + 16.f, 656.f), "Assets/Sprites/middle_ground_sprite.png");
		if (plataforma_cima && plataforma_baixo) {
			obstaculos.incluir(plataforma_cima);
			obstaculos.incluir(plataforma_baixo);
		}
	}
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
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Plataforma(Math::Vector2Df(j * 32.f + 16.f, i * 32.f + 16.f), "Assets/Sprites/middle_ground_sprite.png"));
				if (aux)
					obstaculos.incluir(aux);

				break;
			case 'P':
				criar_jogador('P', Math::Vector2Df(j * 32.f, i * 32.f));

				break;
			case 'B':
				criar_jogador('B', Math::Vector2Df(j * 32.f, i * 32.f));

				break;
			default:
				break;
			}
			j++;
		}
	}

	arq.close();
}
