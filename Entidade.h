#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {

    class Entidade : public Ente {
    protected:
        sf::Vector2f position;
        sf::Texture* textura;
        sf::Sprite* body;
        const float gravidade;

    public:
        Entidade(const char* texturePath = "");
        ~Entidade();
        //execucao
        virtual void inicializar();
        virtual void executar() = 0;
        void desenhar();
        //salvamento
        virtual void salvar() = 0;
        virtual void carregar() = 0;
    };
}
