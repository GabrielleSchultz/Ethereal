#include "Personagem.h"

namespace Entidades {

	namespace Personagens {

		Personagem::Personagem(int nv) : Entidade(), num_vidas(nv), vivo(true)
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