#pragma once
#include "Menu.h"
#include "Texto.h"
#include "TextBox.h"

//baseado fortemente no código do monitor Matheus Burda

namespace Estados {
	namespace Menus {

		class MenuGameOver : public Menu
		{
		private:
			std::string fundo_gameover;
			Controle::ControleUI::TextBox input_nome_jogador;
			ElementosGraficos::Texto nome_jogador;
			ElementosGraficos::Texto pontos_jogador;

		public:
			MenuGameOver();
			~MenuGameOver();
			void executar(float dt);
			void update_pontuacao();
			void desenhar();
			void cria_botoes();
			void salva_pontuacao();
		};
	}

}