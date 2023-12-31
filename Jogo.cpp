#include "Jogo.h"
#include <iostream>
#include "Vector2D.h"

#define DELTA_TIME_FIX 60.f

Jogo::Jogo() : nome("Ethereal - Echoes of the Soul"),
pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico()),
pGerenciadorEventos(Gerenciadores::Eventos::getGerenciador_Eventos()),
pGerenciadorEstados(Gerenciadores::Gerenciador_Estados::getGerenciadorEstados()),
deltaTime(0.f),
dt_multiplier(DELTA_TIME_FIX)
{
    pGerenciadorGrafico->setWindowTitle(nome);
    pGerenciadorEstados->criar_estado(Estados::Tipo::MenuPrincipal);
    //pGerenciadorEstados->criar_estado(Estados::Tipo::MenuRanking);
    executar();
}

Jogo::~Jogo()
{
    pGerenciadorGrafico = nullptr;
    pGerenciadorEventos = nullptr;
    pGerenciadorEstados = nullptr;
}

//Game loop
void Jogo::executar()
{
    while (running())
    {
        clear();
        pollEvents();
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
    pGerenciadorEventos->pollEvents();
}

void Jogo::updateDeltaTime()
{
    deltaTime = clock.restart().asSeconds();
}

void Jogo::clear()
{
    pGerenciadorGrafico->clearWindow();
}

void Jogo::update()
{
    updateDeltaTime();
    if (pGerenciadorEstados->isEmpty())
        pGerenciadorGrafico->closeWindow();
    else
        pGerenciadorEstados->executar(deltaTime * dt_multiplier);
}

void Jogo::draw()
{
    pGerenciadorGrafico->displayWindow();
}
