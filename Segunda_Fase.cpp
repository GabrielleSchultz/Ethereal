#include "Segunda_Fase.h"
#include "Raiva.h"
#include "Vinganca.h"
#include "Plataforma.h"
#include "Poca_Lagrima.h"
#include <fstream>
#include <iostream>

Fases::Segunda_Fase::Segunda_Fase() :
	Fase(),
	chefoes(),
	boss(nullptr)
{
	pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stage2_full_background.png");
	pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stars-Big_1_2_PC.png");
}

Fases::Segunda_Fase::~Segunda_Fase()
{
}

void Fases::Segunda_Fase::executar(float dt)
{
	pGerenciadorGrafico->desenhar("Assets/Backgrounds/Stage2_full_background.png", Math::Vector2Df(0, 0));

	Listas::Lista<Entidades::Entidade>::Iterador jog;
	Entidades::Entidade* jogador = nullptr;

	Listas::Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;

	int j = 0, i = 0, o = 0;
	for (jog = jogadores.get_primeiro(), j = 0; j < jogadores.getTamanho(); jog.operator++(), j++) {
		jogador = jog.operator*();
		//jogador->update(dt);
		jogador->executar(dt);

		for (it = inimigos.get_primeiro(), i = 0; i < inimigos.getTamanho(); it.operator++(), i++) {
			aux = it.operator*();
			//aux->update(dt);
			aux->executar(dt);
			if (!static_cast<Entidades::Personagens::Personagem*>(aux)->getVivo() && aux->getId() == Entidades::ID::boss) {
				Listas::Lista<Entidades::Entidade>::Iterador it_boss = chefoes.get_primeiro();
				if (chefoes.getTamanho() > 1) {
					it_boss.operator++();
					boss = static_cast<Entidades::Personagens::Vinganca*>(it_boss.operator*());
					inimigos.incluir(boss);
				}
				chefoes.remover(aux);
			}
			if (aux->getId() == Entidades::ID::inimigo_raiva) {
				static_cast<Entidades::Personagens::Raiva*>(aux)->perseguir(static_cast<Entidades::Personagens::Jogador*>(jogador));
			}
		}
	}

	for (it = obstaculos.get_primeiro(), o = 0; o < obstaculos.getTamanho(); it.operator++(), o++) {
		aux = it.operator*();
		aux->update(dt);
		//static_cast<Entidades::Obstaculos::Plataforma*>(aux)->obstacular(static_cast<Entidades::Personagens::Jogador*>(jogador));
	}
	pGerenciadorGrafico->desenharEnte("Assets/Backgrounds/Stars-Big_1_2_PC.png", Math::Vector2Df(0, 0));

	remover_sem_vida(&inimigos);
	remover_sem_vida(&jogadores);
}

void Fases::Segunda_Fase::salvar(std::ostringstream* entrada)
{
}

void Fases::Segunda_Fase::criar_inimigos()
{
	srand(time(NULL));

	int i = 0;

	Entidades::Personagens::Raiva* raiva = nullptr;
	for (i = 0; i < rand() % 2 + 3; i++) {
		raiva = new Entidades::Personagens::Raiva();
		if (raiva)
		{
			raiva->setPosition((float)700 + 64 * i, 200);
			inimigos.incluir(raiva);
		}
	}

	for (i = 0; i < rand() % 2 + 3; i++) {
		Entidades::Personagens::Vinganca* chefao = new Entidades::Personagens::Vinganca(50 * i + 50, 25 * i + 25);
		chefao->setPosition(1000, 0);
		chefoes.incluir(chefao);
		//std::cout << "criou um chefão" << std::endl;
	}

	// um chefão por vez!
	Listas::Lista<Entidades::Entidade>::Iterador it = chefoes.get_primeiro();
	boss = static_cast<Entidades::Personagens::Vinganca*>(it.operator*());
	inimigos.incluir(boss);
}

void Fases::Segunda_Fase::criar_obstaculos()
{
	srand(time(NULL));
	int i = 0, x = 15, qtd_pocas = rand() % 6 + 3;

	Entidades::Obstaculos::Poca_Lagrimas* poca = nullptr;
	for (i = 0; i < qtd_pocas; i++, x++) {
		poca = new Entidades::Obstaculos::Poca_Lagrimas(Math::Vector2Df(x * 32.f + 16.f, 624.f), "Assets/Sprites/top_ground_sprite.png");
		if (poca)
			obstaculos.incluir(poca);
	}

	Entidades::Obstaculos::Plataforma* plataforma = nullptr;
	for (i = 0; i < 8 - qtd_pocas; i++, x++) {
		plataforma = new Entidades::Obstaculos::Plataforma(Math::Vector2Df(x * 32.f + 16.f, 624.f), "Assets/Sprites/middle_ground_sprite.png");
		if (plataforma)
			obstaculos.incluir(plataforma);
	}

}

void Fases::Segunda_Fase::criar_cenario(std::string file_path)
{
	std::ifstream arq(file_path);
	if (!arq)
	{
		std::cout << "Não foi possível abrir arquivo de cenário" << std::endl;
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
				// plataforma
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
