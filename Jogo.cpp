#include "Jogo.h"
#include <iostream>


Jogo::Jogo() : nome("Ethereal - Echoes of the Soul"), 
pGerenciadorGrafico (Gerenciadores::Grafico::getGerenciador_Grafico())
{
    pGerenciadorGrafico->setWindowTitle(nome);
	executar();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
    while (pGerenciadorGrafico->isWindowOpen())
    {
        //updateDeltaTime()
        clear();
        //run();
        draw();
    }
}

void Jogo::clear()
{
    pGerenciadorGrafico->clearWindow();
}

void Jogo::draw()
{
    //...
    pGerenciadorGrafico->displayWindow();
}

