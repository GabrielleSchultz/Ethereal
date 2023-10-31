#include "Personagem.h"

namespace Entidades {

	namespace Personagens {

		Personagem::Personagem(int nv, const char* texturePath) : 
		Entidade(texturePath), num_vidas(nv), vivo(true)
		{

		}

		Personagem::~Personagem() 
		{
			vivo = false;
		}

		bool Entidades::Personagens::Personagem::getVivo()
		{
			return vivo;
		}

	}
}