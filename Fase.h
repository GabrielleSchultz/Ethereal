#pragma once

namespace Fases {

	class Fase {
	protected:

	public:
		Fase();
		~Fase();
		virtual void executar();
		void gerenciar_colisoes();
		virtual void criar_inimigos() = 0;
		virtual void criar_obstaculos() = 0;
	};

}