#include "Jogo.h"

#include <iostream>

Jogo::Jogo() : nome("Ethereal - Echoes of the Soul")
{

	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    pGerenciadorGrafico->setWindowTitle(nome);

    while (pGerenciadorGrafico->isWindowOpen())
    {
        //aqui sera muito provavelmente utilizado o gerenciador de eventos
        sf::Event event;
        while (janelaPrincipal.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                janelaPrincipal.close();

        }
        pGerenciadorGrafico->clearWindow();
        pGerenciadorGrafico->displayWindow();
    }
}

void Jogo::inicializaEntidades()
{
}
