#pragma once

#include "Ente.h"

//referencia do código: livro SFML Game Development - Arthur Moreira, Jan Haller

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
		carregarjogo,
		MenuPrincipal,
		MenuSettings,
		singleplayer,
		multiplayer,
		MenuPause,
		save,
		MenuRanking,
		saverranking,
		sair
	};

	class Estado : public Ente
	{
	protected:
		static Gerenciadores::Gerenciador_Estados* pGE;
		bool ativo;
		static bool multiplayer;
		static unsigned int pontuacao_jogo;

	public:

		Estado();
		virtual ~Estado();
		void request_push(Estados::Tipo id_estado);
		void request_pop();
		void request_clear();
		void setAtivo(const bool b);
		bool getAtivo() const;
		virtual void executar(float dt) = 0;
		void salvar(nlohmann::ordered_json& entrada){}
		static void setMultiplayer(const bool b);
		static bool getMultiplayer();
		static void setPontuacao(const unsigned int pontos);
		static unsigned int getPontuacao();
	};

}