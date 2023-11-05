#include "Jogo.h"
#include <iostream>
#include "Vector2D.h"

#include "Tristeza.h"
#include "Vinganca.h"

#define DELTA_TIME_FIX 60.f

Jogo::Jogo() : nome("Ethereal - Echoes of the Soul"), 
pGerenciadorGrafico (Gerenciadores::Grafico::getGerenciador_Grafico()),
pGerenciadorEventos (Gerenciadores::Eventos::getGerenciador_Eventos()),
pGerenciadorColisoes (Gerenciadores::Colisoes::getGerenciador_Colisoes()),
deltaTime (0.f),
dt_multiplier (DELTA_TIME_FIX)
{
    teste = new Entidades::Personagens::Jogador(20, "Assets/Sprites/Pixi_cortado.png");
    raivinha = new Entidades::Personagens::Raiva();
    raivinha2 = new Entidades::Personagens::Raiva();
    sadness = new Entidades::Personagens::Tristeza();
    boss = new Entidades::Personagens::Vinganca();
    teste->setPosition(100, 450);
    raivinha->setPosition(732, 450);
    raivinha2->setPosition(700, 450);
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
    raivinha2->update(deltaTime * dt_multiplier);
    raivinha->perseguir(teste);
    raivinha2->perseguir(teste);
    sadness->update(deltaTime * dt_multiplier);
    boss->update(deltaTime * dt_multiplier);
    
    
    Listas::ListaEntidades inimigos;
    inimigos.incluir(raivinha);
    inimigos.incluir(raivinha2);
    pGerenciadorColisoes->setListaInimigos(&inimigos);
    pGerenciadorColisoes->ColisaoJogInim(teste);
}

void Jogo::draw()
{
    pGerenciadorGrafico->displayWindow();
}

