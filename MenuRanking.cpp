#include "MenuRanking.h"
#include <fstream>
#include <map>

#define QTD_BOTOES 2
#define RANKING_FILEPATH "../Ethereal/Ranking/ranking.txt"
#define RANKING_MAX 10

Estados::Menus::MenuRanking::MenuRanking(): Menu()
{
	titulo.setTexto("Ranking");
	cria_botoes();
	cria_ranking();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuRanking::~MenuRanking()
{
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
			unsigned int pontuacao;
			std::string str_nome;
			std::string str_pontos;
			
			ElementosGraficos::Texto* nome;
			ElementosGraficos::Texto* pontos;

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

void Estados::Menus::MenuRanking::executar()
{
	desenhar();
}
