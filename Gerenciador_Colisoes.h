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
		
		// Singleton
		Colisoes();
		static Gerenciadores::Colisoes* instancia_pGC;
		

	public:
		~Colisoes();
		static Colisoes* getGerenciador_Colisoes();

		void setListaInimigos(Listas::ListaEntidades* i);

		bool Colisao(Entidades::Entidade* e1, Entidades::Entidade* e2);
		void ColisaoJogInim(Entidades::Personagens::Jogador* jog);
		void ColisaoProjInim();
	};



}
