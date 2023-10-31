#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {

    class Entidade : public Ente {
    protected:
        sf::Vector2f posicao;
        sf::Vector2f velocidade;
        sf::Texture* textura;
        sf::RectangleShape corpo;

    public:
        Entidade(const char* texturePath = "");
        ~Entidade();
        //posicao
        sf::Vector2f getPosicao() const;
        float get_pos_X() const;
        float get_pos_Y() const;
        //execucao
        virtual void executar() = 0;
        void desenhar();
        //salvamento
        virtual void salvar() = 0;
        virtual void carregar() = 0;
    };
}
