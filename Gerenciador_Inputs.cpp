#include "Gerenciador_Inputs.h"
#include "Controller.h"

namespace Gerenciadores
{
    Input* Input::instancia_pGI(nullptr);

    Input::Input()
    {
        keyMap.clear();
        observers.clear();
        createKeyMap();
    }

    Input::~Input()
    {
        observers.clear();
    }

    Input* Input::getGerenciador_Inputs()
    {
        if (instancia_pGI == nullptr)
            instancia_pGI = new Gerenciadores::Input();
        return instancia_pGI;
    }

    void Input::notifyKeyPressed(sf::Keyboard::Key key)
    {
        std::vector<Controller*>::iterator it;

        for (it = observers.begin(); it != observers.end(); it++)
        {
            (*it)->notifyKeyPressed(keyMap[key]);
        }
    }

    void Input::notifyKeyReleased(sf::Keyboard::Key key)
    {
        std::vector<Controller*>::iterator it;

        for (it = observers.begin(); it != observers.end(); it++)
        {
            (*it)->notifyKeyReleased(keyMap[key]);
        }
    }

    void Input::adicionar_observer(Controller* pObserver)
    {
        if (pObserver)
            observers.push_back(pObserver);
    }

    void Input::remover_observer(Controller* pObserver)
    {
        if (pObserver)
        {
            std::vector<Controller*>::iterator it = observers.begin();
            while (it != observers.end())
            {
                if ((*it) == pObserver)
                {
                    observers.erase(it);
                }
                it++;
            }
        }
    }

    void Gerenciadores::Input::createKeyMap()
    {
        //cria os pares de Keys do SFML e const char
        keyMap[sf::Keyboard::A] = "A";
        keyMap[sf::Keyboard::B] = "B";
        keyMap[sf::Keyboard::C] = "C";
        keyMap[sf::Keyboard::D] = "D";
        keyMap[sf::Keyboard::E] = "E";
        keyMap[sf::Keyboard::F] = "F";
        keyMap[sf::Keyboard::G] = "G";
        keyMap[sf::Keyboard::H] = "H";
        keyMap[sf::Keyboard::I] = "I";
        keyMap[sf::Keyboard::J] = "J";
        keyMap[sf::Keyboard::K] = "K";
        keyMap[sf::Keyboard::L] = "L";
        keyMap[sf::Keyboard::M] = "M";
        keyMap[sf::Keyboard::N] = "N";
        keyMap[sf::Keyboard::O] = "O";
        keyMap[sf::Keyboard::P] = "P";
        keyMap[sf::Keyboard::Q] = "Q";
        keyMap[sf::Keyboard::R] = "R";
        keyMap[sf::Keyboard::S] = "S";
        keyMap[sf::Keyboard::T] = "T";
        keyMap[sf::Keyboard::U] = "U";
        keyMap[sf::Keyboard::V] = "V";
        keyMap[sf::Keyboard::W] = "W";
        keyMap[sf::Keyboard::X] = "X";
        keyMap[sf::Keyboard::Y] = "Y";
        keyMap[sf::Keyboard::Z] = "Z";

        keyMap[sf::Keyboard::Escape] = "quit";

        keyMap[sf::Keyboard::Delete] = "delete";
        keyMap[sf::Keyboard::Space] = "space";

        keyMap[sf::Keyboard::Up] = "up";
        keyMap[sf::Keyboard::Down] = "down";
        keyMap[sf::Keyboard::Left] = "left";
        keyMap[sf::Keyboard::Right] = "right";
        //...
    }
}