#include "Raiva.h"
#include <time.h>

namespace Entidades {
	namespace Personagens {
		Raiva::Raiva(int nv, int mal, const char* texturePath, ID id) :
			Inimigo(nv, mal, texturePath, id),
			raio(175),
			agilidade(0.0f) {
			srand(time(NULL));
			agilidade = (float)(rand() % 5 + 1) / 10;
		}

		Raiva::~Raiva()
		{

		}

		void Raiva::executar() {

		}

		void Raiva::salvar(std::ostringstream* entrada) {

		}

		void Raiva::update(float dt) {
			desenhar();
		}

		void Raiva::colidir(Entidades::Entidade* e)
		{
			if (e) {
				if(e->getId() == Entidades::ID::projetil)
					setPosition(position.x + 1 * direction.x, position.y);
				if (e->getId() == Entidades::ID::plataforma || e->getId() == Entidades::ID::espinhos || e->getId() == Entidades::ID::poca_lagrima)
					setPosition(position.x, e->getPosition().y - e->getTamanho().y / 2 - tamanho.y / 2);
			}
			
		}

		void Raiva::danificar(Jogador* p)
		{
			p->setNumVidas(p->getNumVidas() - nivel_maldade);
		}

		void Raiva::perseguir(Jogador* p) {

			// perseguir pixi e bity :0
			if (p->getPosition().x >= position.x - raio && p->getPosition().x <= position.x) {
				setPosition(position.x - agilidade, position.y);
			}
			else if (p->getPosition().x >= position.x && p->getPosition().x <= position.x + raio) {
				setPosition(position.x + agilidade, position.y);
			}
		}
	}
}