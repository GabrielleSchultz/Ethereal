#include "Entidade.h"

namespace Entidades{

	Entidade::Entidade(const char* texturePath): Ente(),
	posicao (0.f,0.f),
	velocidade (0.f,0.f)
	{
		textura = new sf::Texture();
		textura->loadFromFile(texturePath);
		corpo.setTexture(textura);
	}

	Entidades::Entidade::~Entidade()
	{
		delete textura;
	}

	float Entidades::Entidade::get_pos_X() const
	{
		return posicao.x;
	}

	float Entidades::Entidade::get_pos_Y() const
	{
		return posicao.y;
	}

	sf::Vector2f Entidades::Entidade::getPosicao() const
	{
		return posicao;
	}

	void Entidade::desenhar()
	{
		pGerenciadorGrafico->desenharEnte(this->corpo);
	}

}