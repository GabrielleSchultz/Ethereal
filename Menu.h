#pragma once

#include <vector>

#include "ControleMenu.h"
#include "Botao.h"
#include "Texto.h"

namespace Estados {

	namespace Menus {
		class Menu : public Estados::Estado {
		protected:
			ElementosGraficos::Texto titulo;
			std::vector<ElementosGraficos::Botao*> botoes;
			int botao_atual;
			std::string fundo;

			Controle::ControleMenu* pControles;
			static Gerenciadores::Grafico* pGG;

		public:
			Menu();
			~Menu();
			void selecionarCima();
			void selecionarBaixo();
			Estados::Tipo getTipoEstado() const;
			virtual void executar(float dt);
			void setFundo(std::string f);
			virtual void desenhar();
			virtual void cria_botoes() = 0;
		};
	}
}