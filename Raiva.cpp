#include "Raiva.h"
#include <time.h>

namespace Entidades {
	namespace Personagens {
		Raiva::Raiva(int nv, int mal, const char* texturePath, ID id):
		Inimigo(nv, mal, texturePath, id),
		raio(175),
		agilidade(0.0f){
			srand(time(NULL));
			agilidade = (float)(rand() % 3 + 1) / 10;
			std::cout << agilidade << std::endl;
		}

		Raiva::~Raiva() {

		}

		void Raiva::executar() {

		}

		void Raiva::danificar(Jogador* p) {
			
			// perseguir pixi e bity :0
			if (p->getPosition().x >= position.x - raio && p->getPosition().x <= position.x) {
				setPosition(position.x - agilidade, position.y);
			}
			else if (p->getPosition().x >= position.x && p->getPosition().x <= position.x + raio) {
				setPosition(position.x + agilidade, position.y);
			}
		}

		void Raiva::salvar() {

		}

		void Raiva::update(float dt) {
			desenhar();
		}
	}
}