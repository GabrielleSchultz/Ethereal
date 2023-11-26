#pragma once
#include "Menu.h"

//baseado fortemente no tutorial do monitor Matheus Burda

namespace Estados {
	namespace Menus {

		class MenuRanking : public Menu {
		private:
			std::vector <ElementosGraficos::Texto*> ranking;
			static const int tam_ranking;
			static const std::string ranking_filepath;
			

		public:
			MenuRanking();
			~MenuRanking();
			void cria_botoes();
			void cria_ranking();
			void desenhar();
			static const int getTamanhoRanking();
			static const std::string getRankingFilepath();
		};
	}
}