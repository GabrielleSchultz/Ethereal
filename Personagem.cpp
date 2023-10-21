#include "Personagem.h"
using namespace Entidades; 
using namespace Personagens; 

Personagem::Personagem(int nv) : Entidade(), num_vidas(nv), vivo(true){

}

Personagem::~Personagem() {
	vivo = false;
}

Personagem::bool getVivo() {
	return vivo;
}
