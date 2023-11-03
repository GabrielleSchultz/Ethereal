#include "Entidade.h"

namespace Entidades {

	const float Entidade::gravidade(9.8f);

	Entidade::Entidade(const char* texturePath, ID identidade) : Ente(),
		caminho_textura(texturePath),
		id (identidade)
	{
		inicializar();
	}

	Entidades::Entidade::~Entidade()
	{
	}

	void Entidade::inicializar()
	{
		pGerenciadorGrafico->carregarTextura(caminho_textura);
	}


	void Entidade::desenhar()
	{
		pGerenciadorGrafico->desenharEnte(caminho_textura, position);
	}

}