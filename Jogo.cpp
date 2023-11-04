#include "Jogo.h"
#include <iostream>
#include "Vector2D.h"

#include "Tristeza.h"
#include "Vinganca.h"

#define DELTA_TIME_FIX 60.f

Jogo::Jogo() : nome("Ethereal - Echoes of the Soul"), 
pGerenciadorGrafico (Gerenciadores::Grafico::getGerenciador_Grafico()),
pGerenciadorEventos (Gerenciadores::Eventos::getGerenciador_Eventos()),
deltaTime (0.f),
dt_multiplier (DELTA_TIME_FIX)
{
    teste = new Entidades::Personagens::Jogador(20, "Assets/Sprites/Pixie_static_sprite.png");
    raivinha = new Entidades::Personagens::Raiva();
    sadness = new Entidades::Personagens::Tristeza();
    boss = new Entidades::Personagens::Vinganca();
    teste->setPosition(100, 450);
    raivinha->setPosition(800, 450);
    sadness->setPosition(450, 200);
    boss->setPosition(150, 450);
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
    teste->update(deltaTime* dt_multiplier);
    raivinha->update(deltaTime * dt_multiplier);
    raivinha->danificar(teste);
    sadness->update(deltaTime * dt_multiplier);
    boss->update(deltaTime * dt_multiplier);
}

void Jogo::draw()
{
    pGerenciadorGrafico->displayWindow();
}

