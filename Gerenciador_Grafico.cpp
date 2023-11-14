#include "Ente.h"

#include "Gerenciador_Grafico.h"
using namespace Gerenciadores;

#define WINDOW_LENGHT 1300
#define WINDOW_HEIGHT 660

#define SPRITE_ERROR "Assets/error_texture.png"


Grafico* Grafico::instancia_pGG(NULL);

Grafico::Grafico()
{
	janelaPrincipal = new sf::RenderWindow(sf::VideoMode(WINDOW_LENGHT, WINDOW_HEIGHT), "", sf::Style::Titlebar | sf::Style::Close);
	cameraJogo.reset(sf::FloatRect(0, 0, WINDOW_LENGHT, WINDOW_HEIGHT));
	janelaPrincipal->setView(cameraJogo);
	if (!carregarTextura(SPRITE_ERROR))
		exit(1);
}

Grafico::~Grafico()
{
	deletarTexturas();
	delete janelaPrincipal;
}

//singleton:
Grafico* Grafico::getGerenciador_Grafico()
{
	//no caso de multithread, usar um thread lock
	if (instancia_pGG == NULL)
		instancia_pGG = new Gerenciadores::Grafico();
	return instancia_pGG;
}

bool Grafico::isWindowOpen()
{
	if (janelaPrincipal->isOpen())
		return true;
	return false;
}

void Grafico::clearWindow()
{
	if (isWindowOpen())
		janelaPrincipal->clear();
}

//sobrecarga com cores
void Gerenciadores::Grafico::clearWindow(sf::Color color)
{
	if (isWindowOpen())
		janelaPrincipal->clear(color);
}
//

void Grafico::displayWindow()
{
	if (isWindowOpen())
		janelaPrincipal->display();
}

void Gerenciadores::Grafico::centralizarCamera(Math::Vector2Df center)
{
	cameraJogo.setCenter(sf::Vector2f(center.x, center.y));
}

void Grafico::setWindowTitle(std::string titulo)
{
	janelaPrincipal->setTitle(titulo);
}

void Grafico::closeWindow()
{
	if (isWindowOpen())
		janelaPrincipal->close();
}

void Gerenciadores::Grafico::zoomOut(float coef)
{
	cameraJogo.zoom(1 + (coef/100));
}

void Gerenciadores::Grafico::zoomIn(float coef)
{
	cameraJogo.zoom(1 - (coef/100));
}

sf::RenderWindow* Gerenciadores::Grafico::getWindow()
{
	return janelaPrincipal;
}

bool Gerenciadores::Grafico::foraDaCamera(Math::Vector2Df pos, sf::Vector2u size)
{
	//if (pos.x + (size.x) > (cameraJogo.getSize().x) || pos.y + (size.y) > (cameraJogo.getSize().y))
	//	return true;
	return false;
}

//para entidades
void Gerenciadores::Grafico::desenharEnte(std::string filePath, Math::Vector2Df pos)
{
	sf::Texture* texture;
	MapaTextura::iterator it = EntityTextures.find(filePath);

	if (it == EntityTextures.end())
		it = EntityTextures.find(SPRITE_ERROR);

	texture = it->second;
	sf::Vector2u size = texture->getSize();

	if (!foraDaCamera(pos, size))
	{
		sf::Sprite sprite;
		sprite.setTexture(*texture);
		sprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
		sprite.setPosition(pos.x, pos.y);

		janelaPrincipal->draw(sprite);
	}
}

void Gerenciadores::Grafico::desenhar(const std::string filePath, Math::Vector2Df pos)
{
	sf::Texture* texture;
	MapaTextura::iterator it = EntityTextures.find(filePath);

	if (it == EntityTextures.end())
		it = EntityTextures.find(SPRITE_ERROR);

	texture = it->second;
	sf::Vector2u size = texture->getSize();

	sf::Sprite sprite;
	sprite.setTexture(*texture);

	janelaPrincipal->draw(sprite);
}

bool Gerenciadores::Grafico::carregarTextura(const std::string filePath)
{
	MapaTextura::iterator map_it = EntityTextures.begin();

	if (EntityTextures.count(filePath) == 1)
		return true;

	else
	{
		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile(filePath))
		{
			return false; 
		}
		EntityTextures.insert(MapaTextura::value_type(filePath, texture));
		return true;
	}

}

void Gerenciadores::Grafico::deletarTexturas()
{
	MapaTextura::iterator entities_it = EntityTextures.begin(), fonts_it = FontTextures.begin();

	while (entities_it != EntityTextures.end() || fonts_it != FontTextures.end())
	{
		if (entities_it->second != NULL && entities_it != EntityTextures.end())
			delete entities_it->second;
		if (fonts_it->second != NULL && fonts_it != FontTextures.end())
			delete fonts_it->second;

		entities_it++;
		fonts_it++;
	}
}

Math::Vector2Df Gerenciadores::Grafico::getDimensao(std::string texturePath)
{
	MapaTextura::iterator it = EntityTextures.find(texturePath);

	if (it == EntityTextures.end())
		it = EntityTextures.find(SPRITE_ERROR);

	sf::Vector2u size = it->second->getSize();
	Math::Vector2Df dimensao((float)size.x, (float)size.y);

	return dimensao;

}