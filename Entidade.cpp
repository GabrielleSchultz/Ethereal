#include "Entidade.h"
using namespace Entidades; 

Entidade::Entidade(): Ente(), x(0), y(0){
}

Entidades::Entidade::~Entidade()
{
}

int Entidades::Entidade::get_pos_X() const
{
	return x;
}

int Entidades::Entidade::get_pos_Y() const
{
	return y;
}
