#include "Refracao.h"
#include "Raiva.h"
#include "Vinganca.h"
#include "Plataforma.h"
#include "Poca_Lagrima.h"
#include <fstream>
#include <iostream>

Fases::Refracao::Refracao() :
	Fase(),
	boss(nullptr),
	boss_ativo(0)
{
	num_fase = 2;
	pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stage2_full_background.png");
	pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Stars-Big_1_2_PC.png");
}

Fases::Refracao::~Refracao()
{
}

void Fases::Refracao::executar(float dt)
{
	if (!fim_de_fase) {
		pGerenciadorGrafico->desenhar("Assets/Backgrounds/Stage2_full_background.png", Math::Vector2Df(0, 0));

		Listas::Lista<Entidades::Entidade>::Iterador jog;
		Entidades::Entidade* jogador = nullptr;

		Listas::Lista<Entidades::Entidade>::Iterador it;
		Entidades::Entidade* aux = nullptr;

		int j = 0, i = 0, o = 0;
		for (jog = jogadores.get_primeiro(), j = 0; j < jogadores.getTamanho(); jog.operator++(), j++) {
			jogador = jog.operator*();
			jogador->executar(dt);

			for (it = inimigos.get_primeiro(), i = 0; i < inimigos.getTamanho(); it.operator++(), i++) {
				aux = it.operator*();
				if (aux->getId() == Entidades::ID::boss) {
					boss = static_cast<Entidades::Personagens::Vinganca*>(aux);
					if (boss_ativo == 0) {
						boss->setAtivo(true);
					}
					if (boss->getAtivo()) {
						aux->executar(dt);
						boss_ativo++;
					}
				}
				else
					aux->executar(dt);
				if (aux->getId() == Entidades::ID::inimigo_raiva) {
					static_cast<Entidades::Personagens::Raiva*>(aux)->perseguir(static_cast<Entidades::Personagens::Jogador*>(jogador));
				}
			}
		}

		for (it = obstaculos.get_primeiro(), o = 0; o < obstaculos.getTamanho(); it.operator++(), o++) {
			aux = it.operator*();
			aux->update(dt);
		}
		pGerenciadorGrafico->desenharEnte("Assets/Backgrounds/Stars-Big_1_2_PC.png", Math::Vector2Df(0, 0));

		gerenciar_colisoes();

		remover_sem_vida(&inimigos);
		remover_sem_vida(&jogadores);

		if (boss_ativo > 0) {
			boss_ativo = 0;
		}
	}
}

void Fases::Refracao::salvar(std::ostringstream* entrada)
{
}

void Fases::Refracao::criar_inimigos()
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
		//Entidades::Personagens::Vinganca* chefao = new Entidades::Personagens::Vinganca(3, 25 * i + 25);
		Entidades::Personagens::Vinganca* chefao = new Entidades::Personagens::Vinganca(25 * i + 30, 25 * i + 25);
		chefao->setPosition(1000, 0);
		if (i == 0)
			chefao->setAtivo(true);
		inimigos.incluir(chefao);
	}
}

void Fases::Refracao::criar_obstaculos()
{
	srand(time(NULL));
	int i = 0, x = 15, qtd_pocas = rand() % 6 + 3;

	Entidades::Obstaculos::Poca_Lagrimas* poca = nullptr;
	for (i = 0; i < qtd_pocas; i++, x++) {
		poca = new Entidades::Obstaculos::Poca_Lagrimas(Math::Vector2Df(x * 32.f + 16.f, 624.f));
		if (poca)
			obstaculos.incluir(poca);
	}

	Entidades::Obstaculos::Plataforma* plataforma = nullptr;
	for (i = 0; i < 8 - qtd_pocas; i++, x++) {
		plataforma = new Entidades::Obstaculos::Plataforma(Math::Vector2Df(x * 32.f + 16.f, 624.f));
		if (plataforma)
			obstaculos.incluir(plataforma);
	}

}

void Fases::Refracao::criar_cenario(std::string file_path)
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
			{
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Plataforma(Math::Vector2Df(j * 32.f + 16.f, i * 32.f + 16.f)));
				if (aux)
					obstaculos.incluir(aux);
			}
				break;
			case '~':
			{
				aux = static_cast<Entidades::Entidade*>(new Entidades::Obstaculos::Poca_Lagrimas(Math::Vector2Df(j * 32.f + 16.f, i * 32.f + 16.f)));
				if (aux)
					obstaculos.incluir(aux);
			}
			break;
			case 'P':
				criar_jogador('P', Math::Vector2Df(j * 32.f, i * 32.f));

				break;
			case 'B':
			{
				if (Estados::Estado::getMultiplayer())
					criar_jogador('B', Math::Vector2Df(j * 32.f, i * 32.f));
			}
				break;
			default:
				break;
			}
			j++;
		}
	}

	arq.close();
}
