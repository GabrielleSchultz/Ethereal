#include "Jogo.h"
#include "SFML/Graphics.hpp"

Jogo::Jogo()
{
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "Ethereal mas nao muito bom");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
    }
}
