#include "MenuGameOver.h"
#include "MenuRanking.h"

#include <fstream>

#define QTD_BOTOES 3

Estados::Menus::MenuGameOver::MenuGameOver() : 
	Menu()
{
	fundo_gameover = "Assets/Backgrounds/gameover.png";
	setFundo(fundo_gameover);
	titulo.setTexto("Fim de Jogo");
	titulo.setPosicao(Math::Vector2Df(545.f, 85.f));
	pontos_jogador.setPosicao(Math::Vector2Df(250.f, 250.f));
	pontos_jogador.setTamanho(50);
	nome_jogador.setPosicao(Math::Vector2Df(400.f, 400.f));
	nome_jogador.setTamanho(40);
	cria_botoes();
	botoes[botao_atual]->setSelecionado(true);
}

Estados::Menus::MenuGameOver::~MenuGameOver()
{
}

void Estados::Menus::MenuGameOver::executar(float dt)
{
	update_pontuacao();
	salva_pontuacao();
	desenhar();
}

void Estados::Menus::MenuGameOver::update_pontuacao()
{
	nome_jogador.setTexto("Seu nome :" + input_nome_jogador.getTexto());
	pontos_jogador.setTexto("Pontuacao: " + std::to_string(pontuacao_jogo));
}

void Estados::Menus::MenuGameOver::desenhar()
{
	pGG->desenhar(fundo, Math::Vector2Df(0, 0));
	titulo.desenhar();
	for (int i = 0; i < botoes.size(); i++)
	{
		botoes[i]->desenhar();
	}
	pontos_jogador.desenhar();
	nome_jogador.desenhar();
}

void Estados::Menus::MenuGameOver::cria_botoes()
{
	std::string textos[QTD_BOTOES] = { "voltar ao menu principal", "ranking", "sair" };
	Estados::Tipo tipos[QTD_BOTOES] = { Estados::Tipo::MenuPrincipal, Estados::Tipo::MenuRanking, Estados::Tipo::sair };

	Estados::Menus::ElementosGraficos::Botao* botao = nullptr;
	for (int i = 0; i < QTD_BOTOES; i++) {
		botao = new Estados::Menus::ElementosGraficos::Botao(Math::Vector2Df(650.f, 50 * i + 500.f), tipos[i]);
		botao->setTexto(textos[i]);
		botoes.push_back(botao);
	}
}

void Estados::Menus::MenuGameOver::salva_pontuacao()
{

	//leitura do arquivo:
	std::ifstream ranking_file_input;
	std::multimap<int, std::string> mapa_nome_pontuacao;

	ranking_file_input.open(MenuRanking::getRankingFilepath(), std::ios::in);
	if (!ranking_file_input)
	{
		std::cout << "Falha ao abrir arquivo de ranking em Menus::GameOverMenu" << std::endl;
		exit(1);
	}

	std::string nome;
	std::string string_pontos;

	for (int i = 0; i < MenuRanking::getTamanhoRanking(); i++)
	{
		std::getline(ranking_file_input, string_pontos);
		std::getline(ranking_file_input, nome);
		if (string_pontos.length() > 0)
			//transforma em inteiro a pontuacao lida
			mapa_nome_pontuacao.insert(std::pair<int, std::string>( std::stoi(string_pontos), nome));
	}

	ranking_file_input.close();

	if (input_nome_jogador.getTexto().length() > 1)
		mapa_nome_pontuacao.insert(std::pair<int, std::string>(pontuacao_jogo, input_nome_jogador.getTexto()));


	//escrita no arquivo:
	std::ofstream ranking_file_output;

	ranking_file_output.open(MenuRanking::getRankingFilepath(), std::ios::out);

	if (!ranking_file_output) {
		std::cout << "Falha ao abrir arquivo de ranking em Menus::GameOverMenu" << std::endl;
		exit(1);
	}

	while (mapa_nome_pontuacao.size() > MenuRanking::getTamanhoRanking())
		mapa_nome_pontuacao.erase(mapa_nome_pontuacao.begin());

	for (auto itr = mapa_nome_pontuacao.rbegin(); itr != mapa_nome_pontuacao.rend(); ++itr) {
		ranking_file_output << (*itr).first << std::endl;
		ranking_file_output << (*itr).second << std::endl;
	}

	ranking_file_output.close();
}
