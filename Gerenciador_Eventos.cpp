#include "Gerenciador_Eventos.h"
namespace Gerenciadores {

    Eventos* Gerenciadores::Eventos::instancia_pGE(nullptr);

    //aqui a ordem de chamada no .h é importante
    Eventos::Eventos() :
    pGerenciadorGrafico(Gerenciadores::Grafico::getGerenciador_Grafico()),
    pGerenciadorEntradas(Gerenciadores::Input::getGerenciador_Inputs()),
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
            case sf::Event::KeyPressed:
            {
                if (ev.key.code == sf::Keyboard::Escape)
                    pGerenciadorGrafico->closeWindow();
                else
                    pGerenciadorEntradas->notifyKeyPressed(ev.key.code);
                break;
            }
            case sf::Event::KeyReleased:
                pGerenciadorEntradas->notifyKeyReleased(ev.key.code);
            }
        }
    }

}