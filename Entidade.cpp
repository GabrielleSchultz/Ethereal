#include "Entidade.h"

namespace Entidades {

	Entidade::Entidade(const char* texturePath) : Ente(),
		gravidade(9.8f)
	{
		inicializar();
		textura = new sf::Texture();
		textura->loadFromFile(texturePath);
		body->setTexture(*textura);
	}

	Entidades::Entidade::~Entidade()
	{
		delete textura;
	}

	void Entidade::inicializar()
	{
	}


	void Entidade::desenhar()
	{
		//pGerenciadorGrafico->desenharEnte(*body);

	}

}