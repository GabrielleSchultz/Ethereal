#include "Jogo.h"
#include <iostream>
#include "Vector2D.h"

#define DELTA_TIME_FIX 60.f

Jogo::Jogo() : nome("Ethereal - Echoes of the Soul"), 
pGerenciadorGrafico (Gerenciadores::Grafico::getGerenciador_Grafico()),
pGerenciadorEventos (Gerenciadores::Eventos::getGerenciador_Eventos()),
deltaTime (0.f),
dt_multiplier (DELTA_TIME_FIX)
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
    //teste:
    teste.setFillColor(sf::Color::White);
    teste.setSize(sf::Vector2f(64.f, 64.f));
    sf::Texture* text = new sf::Texture();
    text->loadFromFile("Assets/Sprites/Pixie_static_sprite.png");
    teste.setTexture(text);
    maxVel = 7.5f;
    acceleration = 0.5f;
    atrito = 0.25f;

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

//vai ser passado como parametro o delta 
void Jogo::update()
{
    updateDeltaTime();
    //update de todos os elementos

    //acceleration
    direction = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        //fixed
        direction.x = -1.f;
        if (currentVelocity.x > -maxVel)
            currentVelocity.x += acceleration * direction.x * deltaTime * dt_multiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        direction.y = -1.f;
        if (currentVelocity.y > -maxVel)
            currentVelocity.y += acceleration * direction.y * deltaTime * dt_multiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        direction.y = 1.f;
        if (currentVelocity.y < maxVel)
            currentVelocity.y += acceleration * direction.y * deltaTime * dt_multiplier;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        direction.x = 1.f;
        if (currentVelocity.x < maxVel)
            currentVelocity.x += acceleration * direction.x * deltaTime * dt_multiplier;
    }

    //atrito
    if (currentVelocity.x > 0.f)
    {
        currentVelocity.x -= atrito * deltaTime * dt_multiplier;
        if (currentVelocity.x < 0.f)
            currentVelocity.x = 0.f;
    }
    else if (currentVelocity.x < 0.f)
    {
        currentVelocity.x += atrito * deltaTime * dt_multiplier;
        if (currentVelocity.x > 0.f)
            currentVelocity.x = 0.f;
    }
    else if (currentVelocity.y > 0.f)
    {
        currentVelocity.y -= atrito * deltaTime * dt_multiplier;
        if (currentVelocity.x < 0.f)
            currentVelocity.x = 0.f;
    }
    else if (currentVelocity.y < 0.f)
    {
        currentVelocity.y += atrito * deltaTime * dt_multiplier;
        if (currentVelocity.y > 0.f)
            currentVelocity.y = 0.f;
    }

    teste.move(currentVelocity.x * deltaTime * dt_multiplier, currentVelocity.y * deltaTime * dt_multiplier);
}

void Jogo::draw()
{
    pGerenciadorGrafico->getWindow()->draw(teste);
    pGerenciadorGrafico->displayWindow();
}

