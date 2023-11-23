#pragma once

#include <vector>

#include "ControleMenu.h"
#include "Botao.h"
#include "Texto.h"

namespace Estados {

	namespace Menus {
		class Menu : public Estados::Estado {
		protected:
			Texto titulo;
			std::vector<Botao*> botoes;
			int botao_atual;

			Controle::ControleMenu* pControles;
			static Gerenciadores::Grafico* pGG;

		public:
			Menu();
			~Menu();
			//void inicializaIterator();
			void selecionarCima();
			void selecionarBaixo();
			Estados::Tipo getTipoEstado() const;
			void executar(float dt);
			virtual void desenhar();
			virtual void cria_botoes() = 0;
		};
	}
}