#include "Inimigo.h"

namespace Entidades {

	namespace Personagens {

		Inimigo::Inimigo(int nv, int mal) : Personagem(nv), nivel_maldade(mal) {

		}

		Entidades::Personagens::Inimigo::~Inimigo()
		{
		}
	}
}