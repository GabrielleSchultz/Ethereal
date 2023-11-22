#include "Personagem.h"

namespace Entidades {

	namespace Personagens {

		Personagem::Personagem(int nv, const char* texturePath, ID id) :
			Entidade(texturePath, id), num_vidas(nv)
		{

		}

		Personagem::~Personagem()
		{
		}

		bool Entidades::Personagens::Personagem::getVivo()
		{
			// se saiu de tela morre :P
			return (num_vidas > 0 && position.y < 700);
		}

		int Personagem::getNumVidas() const
		{
			return num_vidas;
		}

		void Personagem::setNumVidas(const int nv)
		{
			num_vidas = nv;
		}
	}
}