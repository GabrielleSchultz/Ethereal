#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

namespace Entidades {

    class Entidade : public Ente {
    protected:
        //isto aqui vamos transformar num template coordenada
        int x;
        int y;
        int velocidade;
        //coordenada de posicao

    public:
        Entidade();
        ~Entidade();
        int get_pos_X() const;
        int get_pos_Y() const;
        virtual void executar() = 0;
        virtual void salvar() = 0;

    };
}
