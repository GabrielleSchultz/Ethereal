#include "Inimigo.h"

namespace Entidades {

	namespace Personagens{

		Inimigo::Inimigo(int nv, int mal, const char* texturePath) :
		Personagem (nv, texturePath)
		{
		}

		Inimigo::~Inimigo()
		{
		}

	}
}