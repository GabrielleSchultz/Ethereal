#include "Vinganca.h"

Entidades::Personagens::Vinganca::Vinganca(int nv, int mal, const char* texturePath, ID id):
Inimigo(nv, mal, texturePath, id){

}

Entidades::Personagens::Vinganca::~Vinganca() {

}

void Entidades::Personagens::Vinganca::executar() {

}

void Entidades::Personagens::Vinganca::danificar(Jogador* p) {

}

void Entidades::Personagens::Vinganca::salvar(std::ostringstream* entrada) {

}

void Entidades::Personagens::Vinganca::update(float dt) {
	desenhar();
}