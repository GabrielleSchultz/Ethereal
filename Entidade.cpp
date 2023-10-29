#include "Entidade.h"

namespace Entidades{

	Entidade::Entidade(const char* texturePath): Ente(), x(0), y(0)
	{
		sf::Texture teste_textura;
		teste_textura.loadFromFile(texturePath);
		corpo.setTexture(&teste_textura);
	}

	Entidades::Entidade::~Entidade()
	{
		delete textura;
	}

	float Entidades::Entidade::get_pos_X() const
	{
		return x;
	}

	float Entidades::Entidade::get_pos_Y() const
	{
		return y;
	}

	sf::Vector2f Entidades::Entidade::getPosicao() const
	{
		sf::Vector2f posicao(x, y);
		return posicao;
	}

	void Entidade::desenhar()
	{
		pGerenciadorGrafico->desenharEnte(this);
	}

}