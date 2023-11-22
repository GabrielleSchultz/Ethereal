#pragma once

namespace Gerenciadores {
	class Gerenciador_Estados;
}

namespace Estados
{
	enum class Tipo
	{
		vazio,
		GameState, //gameplay
		TitleScreen, 
		MenuPrincipal,
		MenuPause,
		Ranking
	};

	class Estado
	{
	protected:
		static Gerenciadores::Gerenciador_Estados* pGE;
		bool sair;

	public:

		Estado();
		virtual ~Estado();
		void request_push(Estados::Tipo id_estado);
		void request_pop();
		void request_clear();
	};

}