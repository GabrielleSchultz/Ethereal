#include "Tristeza.h"

#define FREQUENCIA_LANCAMENTO 1000
#define MOVIMENTACAO 10

Entidades::Personagens::Tristeza::Tristeza(int nv, int mal, const char* texturePath, ID id) :
	Inimigo(nv, mal, texturePath, id),
	lancamento(0),
	projeteis(),
	x_maximo(0),
	x_minimo(0)
{
	setDirection(1.f, 0);
	setVelocidade(0.05f, 0);
}

Entidades::Personagens::Tristeza::~Tristeza()
{
	projeteis.clear();
}

void Entidades::Personagens::Tristeza::executar()
{
}

void Entidades::Personagens::Tristeza::danificar(Jogador* p)
{
	if (p)
		p->setNumVidas(p->getNumVidas() - nivel_maldade);
}

void Entidades::Personagens::Tristeza::salvar(nlohmann::ordered_json& entrada)
{
	salvarInimigo(entrada);
	projeteis.salvar(entrada);
}

void Entidades::Personagens::Tristeza::update(float dt)
{
	// não é afetado pela gravidade, levita no ar !!
	// talvez colocar em outro método (??)
	position.y -= gravidade * dt;

	if (lancamento == FREQUENCIA_LANCAMENTO) {
		lancar_projetil();
		lancamento = 0;
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

	if (position.x > x_maximo)
		setDirection(-1, 0);
	else if (position.x < x_minimo)
		setDirection(1, 0);

	setPosition( Math::Vector2Df(position.x + currentVelocity.x * dt * direction.x, position.y));

	desenhar();
}

void Entidades::Personagens::Tristeza::lancar_projetil()
{
	Entidades::Projetil* projetil = nullptr;
	projetil = new Entidades::Projetil("Assets/Sprites/teardrop_projectile_cortado.png", nivel_maldade, 2);
	projetil->setAtirador(this);
	projetil->setDirection(0, 1);
	projetil->setPosition(position.x, position.y);
	projeteis.incluir(projetil);
}

void Entidades::Personagens::Tristeza::colidir(Entidades::Entidade* e)
{
	if (e) {
		if (e->getId() == Entidades::ID::jogador)
			danificar(static_cast<Entidades::Personagens::Jogador*>(e));
	}
}

Listas::ListaEntidades* Entidades::Personagens::Tristeza::getProjeteis()
{
	return &projeteis;
}

void Entidades::Personagens::Tristeza::setMovimentacao(const float x)
{
	x_minimo = x - MOVIMENTACAO;
	x_maximo = x + MOVIMENTACAO;
}
