#include "Vinganca.h"

#define FREQUENCIA_TELETRANSPORTE 5000
#define FREQUENCIA_LANCAMENTO 1500

Entidades::Personagens::Vinganca::Vinganca(int nv, int mal, const char* texturePath, ID id) :
	Inimigo(nv, mal, texturePath, id),
	teletransporta(0), lancamento(0)
{
	if (Entidades::Personagens::Jogador::getNumJogadores() == 2)
		nivel_maldade /= 4;
}

Entidades::Personagens::Vinganca::~Vinganca() {
	projeteis.clear();
}

void Entidades::Personagens::Vinganca::executar() {

}

void Entidades::Personagens::Vinganca::danificar(Jogador* p) {
	if (Jogador::getNumJogadores() == 1) {
		p->setNumVidas(p->getNumVidas() - nivel_maldade);
	}
	else {
		p->setNumVidas(p->getNumVidas() - nivel_maldade / 5);
	}
}

void Entidades::Personagens::Vinganca::colidir(Entidades::Entidade* e)
{
	if (e) {
		if (e->getId() == Entidades::ID::plataforma || e->getId() == Entidades::ID::espinhos || e->getId() == Entidades::ID::poca_lagrima)
			setPosition(position.x, e->getPosition().y - e->getTamanho().y / 2 - tamanho.y / 2);
		else if (e->getId() == Entidades::ID::jogador) {
			static_cast<Entidades::Personagens::Jogador*>(e)->setNumVidas(0);
			teletransporte();
		}
	}
}

void Entidades::Personagens::Vinganca::salvar(std::ostringstream* entrada) {

}

void Entidades::Personagens::Vinganca::update(float dt) {
	if (teletransporta == FREQUENCIA_TELETRANSPORTE) {
		teletransporte();
	}
	teletransporta++;

	if (lancamento == FREQUENCIA_LANCAMENTO) {
		lancar_projeteis();
	}
	lancamento++;

	//projeteis.executar(dt);
	Listas::Lista<Entidades::Entidade>::Iterador it;
	Entidades::Entidade* aux = nullptr;
	int i = 0;
	for (it = projeteis.get_primeiro(), i = 0; i < projeteis.getTamanho(); it.operator++(), i++) {
		aux = it.operator*();
		if (aux != nullptr) {
			aux->update(dt);
		}
	}

	desenhar();
}

void Entidades::Personagens::Vinganca::teletransporte() {
	srand(time(NULL));

	//#define WINDOW_LENGHT 1300
	//#define WINDOW_HEIGHT 660
	float x = rand() % 11 * 100.f + 100.f;
	float y = rand() % 5 * 100.f + 100.f;
	// melhorar depois
	while (x == position.x || y == position.y) {
		float x = rand() % 11 * 100.f + 100.f;
		float y = rand() % 5 * 100.f + 100.f;
	}
	setPosition(Math::Vector2Df(x, y));
	//std::cout << x << " " << y << std::endl;

	teletransporta = 0;
	lancar_projeteis();
}

void Entidades::Personagens::Vinganca::lancar_projeteis() {
	Entidades::Projetil* projetil = nullptr;
	Math::Vector2Df direcoes[] = { Math::Vector2Df(1, 0), Math::Vector2Df(0, 1), Math::Vector2Df(-1, 0), Math::Vector2Df(0, -1), Math::Vector2Df(1, 1), Math::Vector2Df(1, -1), Math::Vector2Df(-1, -1), Math::Vector2Df(-1, 1) };

	for (int i = 0; i < 8; i++) {
		projetil = new Entidades::Projetil("Assets/Sprites/boss_bubble.png", nivel_maldade, 4);
		projetil->setAtirador(this);
		projetil->setDirection(direcoes[i]);
		projetil->setPosition(position.x, position.y);
		projeteis.incluir(projetil);
	}

	lancamento = 0;
}

Listas::ListaEntidades* Entidades::Personagens::Vinganca::getProjeteis()
{
	return &projeteis;
}