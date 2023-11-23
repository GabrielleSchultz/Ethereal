#include "Jogo.h"
#include <iostream>
#include "Vector2D.h"

//#include "Tristeza.h"
//#include "Vinganca.h"

#include "Botao.h"

#define DELTA_TIME_FIX 60.f

Jogo::Jogo() : nome("Ethereal - Echoes of the Soul"),
pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico()),
pGerenciadorEventos(Gerenciadores::Eventos::getGerenciador_Eventos()),
deltaTime(0.f),
dt_multiplier(DELTA_TIME_FIX)
//pfase()
{
    /*pfase.criar_cenario("Mapas/Fase1.txt");
    pfase.criar_cenario("Mapas/Fase2.txt");
    pfase.criar_inimigos();
    pfase.criar_obstaculos();*/
    pGerenciadorGrafico->setWindowTitle(nome);
    pGerenciadorGrafico->carregarTextura("Assets/Backgrounds/Menu.png");
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
    //pfase.executar(deltaTime * dt_multiplier);
    //pfase.gerenciar_colisoes();
    pGerenciadorGrafico->desenhar("Assets/Backgrounds/Menu.png", Math::Vector2Df(0,0));
    Menu::Botao* button;
    button = new Menu::Botao(Math::Vector2Df(0, 0), Math::Vector2Df(1000, 1000), "");
    button->setTexto("alo");
    button->executar(deltaTime * dt_multiplier);
}

void Jogo::draw()
{
    pGerenciadorGrafico->displayWindow();
}
