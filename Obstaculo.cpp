#include "Obstaculo.h"

namespace Entidades {

	namespace Obstaculos
	{
		Obstaculo::Obstaculo(Math::Vector2Df posicao, const char* texture, ID id) :
		Entidade (texture, id, posicao), danoso (false)
		{
		}
		Obstaculo::~Obstaculo()
		{
		}
	}

}