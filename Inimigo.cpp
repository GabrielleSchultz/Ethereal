#include "Inimigo.h"

namespace Entidades {

	namespace Personagens{

		Inimigo::Inimigo(int nv, int mal, const char* texturePath, ID id) : 
		Personagem (nv, texturePath, id),
		nivel_maldade(mal)
		{
		}

		Inimigo::~Inimigo()
		{
		}

		void Inimigo::salvarInimigo(nlohmann::ordered_json& entrada)
		{
			salvarPersonagem(entrada);
			entrada["maldade"] = nivel_maldade;
		}

	}
}