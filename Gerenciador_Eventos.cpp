#include "Gerenciador_Eventos.h"
namespace Gerenciadores {

    Eventos* Gerenciadores::Eventos::instancia_pGE(nullptr);

    //aqui a ordem de chamada no .h é importante
    Eventos::Eventos() :
    pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico()),
    pJanela(pGerenciadorGrafico->getWindow())
    {
    }

    Eventos::~Eventos()
    {
    }

    Eventos* Eventos::getGerenciador_Eventos()
    {
        if (instancia_pGE == nullptr)
            instancia_pGE = new Gerenciadores::Eventos();
        return instancia_pGE;
    }

    void Eventos::pollEvents()
    {
        sf::Event ev;

        while (pGerenciadorGrafico->getWindow()->pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                pGerenciadorGrafico->closeWindow();
                break;
            //isso vai passar para o inputHandler:
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape)
                    pGerenciadorGrafico->closeWindow();
                break;
            }
        }
    }

}