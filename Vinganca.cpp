#include "Vinganca.h"

int Entidades::Personagens::Vinganca::Vinganca::cont_frequencia(4500);

Entidades::Personagens::Vinganca::Vinganca(int nv, int mal, const char* texturePath, ID id) :
	Inimigo(nv, mal, texturePath, id),
	teletransporta(0),
	frequencia_teletransporte(cont_frequencia),
	ativo(false)
{
	cont_frequencia -= 500;
	if (Entidades::Personagens::Jogador::getNumJogadores() == 2)
		nivel_maldade /= 4;
}

Entidades::Personagens::Vinganca::~Vinganca() {
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

void Entidades::Personagens::Vinganca::salvar(nlohmann::ordered_json& entrada)
{
	salvarInimigo(entrada);
	entrada["teletransporta"] = teletransporta;
	entrada["ativo"] = ativo;
}

void Entidades::Personagens::Vinganca::carregar(nlohmann::ordered_json& saida)
{
	carregarInimigo(saida);
	teletransporta = (saida["teletransporta"].template get<int>());
	ativo = (saida["ativo"].template get<bool>());
}

void Entidades::Personagens::Vinganca::update(float dt) {
	if (teletransporta == frequencia_teletransporte) {
		teletransporte();
	}
	teletransporta++;

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
}

void Entidades::Personagens::Vinganca::setAtivo(bool b)
{
	ativo = b;
}

bool Entidades::Personagens::Vinganca::getAtivo()
{
	return ativo;
}
