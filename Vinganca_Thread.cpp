/*#include "Vinganca_Thread.h"

void Entidades::Personagens::Inimigos::Vinganca_Thread::run()
{
    while (this->num_vidas > 0)
    {
        this->lock();
        if (!novoFrame)
        {
            this->unlock();
            continue;
        }
        novo_frame = false;
        this->executar();
        this->unlock();
    }
}

Entidades::Personagens::Inimigos::Vinganca_Thread::Vinganca_Thread(int nv, int mal, const char* texturePath, ID id):
	Vinganca(nv, mal, texturePath, id),
	Thread(),
	novo_frame(false)
{
}

Entidades::Personagens::Inimigos::Vinganca_Thread::~Vinganca_Thread()
{
}

void Entidades::Personagens::Inimigos::Vinganca_Thread::novoFrame()
{
	novo_frame = true;
}

void Entidades::Personagens::Inimigos::Vinganca_Thread::salvar()
{
    std::ofstream arquivo("thread.json", std::ofstream::binary);
    if (!arquivo)
    {
        std::cout << "Arquivo não existe" << std::endl;
        exit(2);
    }
    arquivo << "[" << std::endl;

    arquivo << "    {" << std::endl << "        \"posicao\": [" << std::endl << "            " \
        << position.x << "," << std::endl << "            " << position.y << std::endl << \
        "        ]," << std::endl << "        \"velocidade\": [" << std::endl << "            " << currentVelocity.x << "," << \
        std::endl << "            " << currentVelocity.y << std::endl << "        ]" << std::endl << "    }" << std::endl;
    
    arquivo << "]";
    arquivo.close();
}
*/