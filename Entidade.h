#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include <fstream>

namespace Entidades {

    enum class ID
    {
        vazio,
        jogador,
        inimigo_tristeza,
        inimigo_raiva,
        inimigo_si,
        boss,
        plataforma,
        espinhos,
        poca_lagrima,
        projetil
    };

    class Entidade : public Ente {
    protected:
        Math::Vector2Df position;
        Math::Vector2Df tamanho;
        ID id;
        static const float gravidade;
        const char* caminho_textura;

    public:
        Entidade(const char* texturePath = "", ID identidade = ID::vazio);
        virtual ~Entidade();
        //execucao
        virtual void inicializar();
        void executar(float dt);
        virtual void update(float dt) = 0;
        void desenhar();
        //salvamento
        virtual void salvar(std::ostringstream* entrada) = 0;
        void setPosition(float x, float y);
        void setPosition(Math::Vector2Df v);
        void setTamanho(float x, float y);

        // m todo para o inimigo raiva perseguir
        Math::Vector2Df getPosition() const;
        Math::Vector2Df getTamanho() const;

        ID getId();
    };
}