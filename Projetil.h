#pragma once
#include "Entidade.h"
#include "DynamicBody.h"

namespace Entidades {

	class Projetil : public Entidade, public DynamicBody {
	
	private:
		int velocidade;

	public:
		Projetil();
		~Projetil();
		void executar();
		void salvar();
	};

}
