#include "MenuRanking.h"
#include <fstream>
#include <map>

#define QTD_BOTOES 2
#define RANKING_FILEPATH "../Ethereal/Ranking/ranking.txt"
#define RANKING_MAX 10

const int Estados::Menus::MenuRanking::MenuRanking::tam_ranking(RANKING_MAX);
const std::string Estados::Menus::MenuRanking::MenuRanking::ranking_filepath(RANKING_FILEPATH);

Estados::Menus::MenuRanking::MenuRanking(): 
	Menu(),
	ranking()
{
	titulo.setTexto("Ranking");
	cria_botoes();
	cria_ranking();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuRanking::~MenuRanking()
{
	ranking.clear();
}

void Estados::Menus::MenuRanking::cria_botoes()
{
	std::string textos[QTD_BOTOES] = {"voltar", "sair"};
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::vazio, Estados::Tipo::sair};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 450.f), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuRanking::cria_ranking()
{
	try {
		std::ifstream arq(RANKING_FILEPATH);
		if (arq)
		{
			std::string str_nome;
			std::string str_pontos;
			
			ElementosGraficos::Texto* nome;
			ElementosGraficos::Texto* pontos;

			for (int i = 0; i < RANKING_MAX; i++)
			{
				std::getline(arq, str_pontos);
				std::getline(arq, str_nome);
				
				nome = new ElementosGraficos::Texto();
				nome->setTexto(str_nome);
				nome->setTamanho(25);
				nome->setPosicao(Math::Vector2Df(555, 222 + 50 * i));
				pontos = new ElementosGraficos::Texto();
				pontos->setTexto(str_pontos);
				pontos->setTamanho(25);
				pontos->setPosicao(Math::Vector2Df(750, 222 + 50 * i));
				ranking.push_back(nome);
				ranking.push_back(pontos);
			}
			arq.close();
		}
		else
		{
			std::string error = "Não foi possível abrir arquivo de ranking";
			throw (error);
		}
	}
	catch (std::string error_message)
	{
		std::cout << error_message << std::endl;
		exit(1);
	}
}

void Estados::Menus::MenuRanking::desenhar()
{
	pGG->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0, 0));
	titulo.desenhar();
	for (int i = 0; i < QTD_BOTOES; i++)
	{
		botoes[i]->desenhar();
	}
	for (int i = 0; i < RANKING_MAX; i++)
	{
		ranking[i]->desenhar();
	}
}

const int Estados::Menus::MenuRanking::getTamanhoRanking()
{
	return tam_ranking;
}

const std::string Estados::Menus::MenuRanking::getRankingFilepath()
{
	return ranking_filepath;
}
