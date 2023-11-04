#include "Entidade.h"

namespace Entidades {

	const float Entidade::gravidade(9.8f);

	Entidade::Entidade(const char* texturePath, ID identidade) : Ente(),
		caminho_textura(texturePath),
		id (identidade),
		position (0,0)
	{
		inicializar();
	}

	Entidades::Entidade::~Entidade()
	{
	}

	void Entidade::inicializar()
	{
		pGerenciadorGrafico->carregarTextura(caminho_textura);
		tamanho = pGerenciadorGrafico->getDimensao(caminho_textura);
		std::cout << tamanho.x << tamanho.y << std::endl;
	}


	void Entidade::desenhar()
	{
		pGerenciadorGrafico->desenharEnte(caminho_textura, position);
	}

	void Entidade::setPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void Entidade::setTamanho(float x, float y)
	{
		tamanho.x = x;
		tamanho.y = y;
	}

	Math::Vector2Df Entidade::getPosition()
	{
		return position;
	}

	Math::Vector2Df Entidade::getTamanho()
	{
		return tamanho;
	}

}