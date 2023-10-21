#include "Entidade.h"
using namespace Entidades; 

Entidade::Entidade(): Ente(), x(0), y(0){
}

int Entidade::getX() {
	return x;
}

int Entidade::getY() {
	return y;
}
