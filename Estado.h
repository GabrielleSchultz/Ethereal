#pragma once

#include "Ente.h"

namespace Gerenciadores {
	class Gerenciador_Estados;
}

namespace Estados
{
	enum class Tipo
	{
		vazio,
		GameState,
		Gameover,
		MenuFases,
		Fase1,
		Fase2,
		MenuPrincipal,
		MenuSettings,
		MenuPause,
		MenuRanking,
		sair
	};

	class Estado : public Ente
	{
	protected:
		static Gerenciadores::Gerenciador_Estados* pGE;
		bool ativo;

	public:

		Estado();
		virtual ~Estado();
		void request_push(Estados::Tipo id_estado);
		void request_pop();
		void request_clear();
		void setAtivo(bool b);
		bool getAtivo();
		virtual void executar(float dt) = 0;
		void salvar(std::ostringstream* entrada){}
	};

}