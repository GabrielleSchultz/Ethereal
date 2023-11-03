#include "Entidade.h"

namespace Entidades {

	Entidade::Entidade(const char* texturePath, ID identidade) : Ente(),
		caminho_textura(texturePath),
		id (identidade),
		gravidade(9.8f)
	{
		inicializar();
	}

	Entidades::Entidade::~Entidade()
	{
	}

	void Entidade::inicializar()
	{
		
	}


	void Entidade::desenhar()
	{
		pGerenciadorGrafico->desenharEnte(caminho_textura, position);
	}

}