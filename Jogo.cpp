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

    while (pGerenciadorGrafico->isWindowOpen())
    {
        //aqui sera muito provavelmente utilizado o gerenciador de eventos
        while (!pGerenciadorGrafico->windowClosed())
        {

        }
        pGerenciadorGrafico->clearWindow();
        pGerenciadorGrafico->displayWindow();
    }
}

void Jogo::inicializaEntidades()
{
}
