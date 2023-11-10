#include "Personagem.h"

namespace Entidades {

	namespace Personagens {

		Personagem::Personagem(int nv, const char* texturePath, ID id) : 
		Entidade(texturePath, id), num_vidas(nv), vivo(true)
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