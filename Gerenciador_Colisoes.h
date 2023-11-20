#pragma once
#include "ListaEntidades.h"

namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
}

namespace Gerenciadores
{
	class Colisoes
	{
	private:
		Listas::ListaEntidades* inimigos;
		Listas::ListaEntidades* jogadores;

		// Singleton
		Colisoes();
		static Gerenciadores::Colisoes* instancia_pGC;


	public:
		~Colisoes();
		static Colisoes* getGerenciador_Colisoes();

		void setListaInimigos(Listas::ListaEntidades* i);
		void setListaJogadores(Listas::ListaEntidades* j);

		bool Colisao(Entidades::Entidade* e1, Entidades::Entidade* e2);
		void ColisaoJogInim();
		void ColisaoProjInim();
		void ColisaoProjJog();
	};



}
