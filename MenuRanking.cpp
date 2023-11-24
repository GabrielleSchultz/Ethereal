#include "MenuRanking.h"
#include <fstream>
#include <map>

#define RANKING_FILEPATH "../Ethereal/Data/Ranking/ranking.txt"
#define RANKING_MAX 10

Estados::Menus::MenuRanking::MenuRanking(): Menu()
{
}

Estados::Menus::MenuRanking::~MenuRanking()
{
}

void Estados::Menus::MenuRanking::cria_botoes()
{
	std::string textos[] = { "voltar", "sair"};

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < textos->size(); i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 500.f));
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
			unsigned int pontuacao;
			std::string str_nome;
			std::string str_pontos;
			
			ElementosGraficos::Texto* str_nome_pontos;

			for (int i = 0; i < RANKING_MAX; i++)
			{
				std::getline(arq, str_pontos);
				std::getline(arq, str_nome);

				//alinha os pontos na mesma largura
				if (str_pontos.length() > 0)
				{
					pontuacao = std::stoi(str_pontos);

					str_pontos += std::to_string(pontuacao / 1000);
					pontuacao %= 1000;

					str_pontos += std::to_string(pontuacao / 100);
					pontuacao %= 100;

					str_pontos += std::to_string(pontuacao / 10);
					pontuacao %= 10;

					str_pontos += std::to_string(pontuacao);
				}
				str_nome_pontos = new ElementosGraficos::Texto();
				
				ranking.push_back(str_nome_pontos);
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
	for (int i = 0; i < botoes.size(); i++)
	{
		botoes[i]->desenhar();
	}
	for (int i = 0; i < ranking.size(); i++)
	{
		ranking[i]->desenhar();
	}
}
