#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		Personagem(int nv) : Entidade(), num_vidas(nv), vivo(true){

		}

		~Personagem() {
			vivo = false;
		}

		bool getVivo() {
			return vivo;
		}
	}
}