#include "TextBox.h"

Controle::ControleUI::TextBox::TextBox() : Controller()
{
    pGerenciadorInput->adicionar_observer(this);

}

Controle::ControleUI::TextBox::~TextBox()
{
	pGerenciadorInput->remover_observer(this);
}

void Controle::ControleUI::TextBox::notifyKeyPressed(std::string key)
{
    if (key == "backspace") {
        if (texto.size() > 0)
            texto.pop_back();
    }

    if (key == "space") {
        texto += " ";
    }

    //caractere válido
    else if (key.length() == 1) { 
        texto += key;
    }
    //caractere nao valido
    else
        return;
}

std::string Controle::ControleUI::TextBox::getTexto() const
{
    return texto;
}

void Controle::ControleUI::TextBox::resetarTexto()
{
    texto = "";
}

