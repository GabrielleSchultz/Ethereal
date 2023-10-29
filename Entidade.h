#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {

    class Entidade : public Ente {
    protected:
        //isto aqui vamos transformar num template coordenada
        float x, y;
        sf::Texture* textura;
        sf::RectangleShape corpo;

    public:
        Entidade(const char* texturePath = "");
        ~Entidade();
        float get_pos_X() const;
        float get_pos_Y() const;
        virtual void executar() = 0;
        virtual void salvar() = 0;
        sf::Vector2f getPosicao() const;
        void desenhar();

    };
}
