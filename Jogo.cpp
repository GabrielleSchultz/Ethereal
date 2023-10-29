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

//Game loop
void Jogo::executar()
{
    while (running())
    {
        updateDeltaTime();
        clear();
        update();
        draw();
    }
}

bool Jogo::running()
{
    if (pGerenciadorGrafico->isWindowOpen())
        return true;
    return false;
}

void Jogo::pollEvents()
{
    while (pGerenciadorGrafico->getWindow()->pollEvent(ev))
    {
        switch (ev.type)
        {
        case sf::Event::Closed:
            pGerenciadorGrafico->closeWindow();
            break;
        case sf::Event::KeyPressed:
            if (ev.key.code == sf::Keyboard::Escape)
                pGerenciadorGrafico->closeWindow();
            break;
        }
    }
}

void Jogo::updateDeltaTime()
{
    //...update delta time
}

void Jogo::clear()
{
    pGerenciadorGrafico->clearWindow();
}

void Jogo::update()
{
    pollEvents();
    //update de todos os elementos
}

void Jogo::draw()
{
    //desenhar todos os elementos
    pGerenciadorGrafico->displayWindow();
}

