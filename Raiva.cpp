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

		void Raiva::colidir()
		{
			setPosition(position.x + 1, position.y);
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