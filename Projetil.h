#pragma once
#include "Entidade.h"

namespace Entidades {

	class Projetil : public Entidade {
	
	private:
		int velocidade;

	public:
		Projetil();
		~Projetil();
		void executar();
		void salvar();
	};

}
