#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"
#include <fstream>

//salvamento com o auxílio de Edison Furusato Oda: https://github.com/0x4D4453/GOTY-TEST

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
        Entidade(const char* texturePath = "", ID identidade = ID::vazio, Math::Vector2Df pos = Math::Vector2Df(0.f,0.f));
        virtual ~Entidade();
        //execucao
        virtual void inicializar();
        void executar(float dt);
        virtual void update(float dt) = 0;
        void desenhar();
        void setPosition(float x, float y);
        void setPosition(Math::Vector2Df v);
        void setTamanho(float x, float y);
        Math::Vector2Df getPosition() const;
        Math::Vector2Df getTamanho() const;

        //salvamento
        void salvarEntidade(nlohmann::ordered_json& entrada);
        virtual void salvar(nlohmann::ordered_json& entrada) = 0;
        void carregarDadosEntidade(nlohmann::ordered_json& saida);
        virtual void carregar(nlohmann::ordered_json& saida) = 0;

        ID getId();
    };
}