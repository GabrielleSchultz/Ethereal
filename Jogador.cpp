#include "Jogador.h"

#define FREQUENCIA_TIRO 100
#define PLAYER_MAXVEL 4

//jumping
#define DURACAO_PULO 2
#define ALTURA_PULO 128

int Entidades::Personagens::Jogador::numJogadores(0);
unsigned int Entidades::Personagens::Jogador::pontos(0);

namespace Entidades {

	namespace Personagens {
		Jogador::Jogador(int nv, const char* texturePath, JogadorNum player, ID id) :
			Personagem(nv, texturePath, id),
			isGrounded(false),
			isJumping(false),
			Player(player),
			jumpSpeed(sqrtf(gravityScale * 0.2 * ALTURA_PULO)),
			gravityCataliser(0.6f),
			projeteis(),
			projeteis_lancados(),
			lancamento(FREQUENCIA_TIRO),
			facingRight(true),
			gravityScale (ALTURA_PULO / (2 * DURACAO_PULO * DURACAO_PULO))
		{
			pControles = new Controle::ControleJogador();
			numJogadores++;
			inicializa();
		}

		Jogador::~Jogador()
		{
			for (int i = 0; i < projeteis_lancados.size(); i++) {
				delete(projeteis_lancados[i]);
			}
			projeteis_lancados.clear();
			projeteis.clear();
			pControles = nullptr;
		}

		void Jogador::inicializa()
		{
			pControles->setJogador(this);

			if (Player == 2)
			{
				pControles->setKeyCommands("up", "right", "left", "down", "delete");
			}

			max_vel = PLAYER_MAXVEL;
		}

		void Jogador::update(float dt)
		{
			mover(dt);
			Listas::Lista<Entidades::Entidade>::Iterador it;
			Entidades::Entidade* aux = nullptr;
			int p = 0;
			for (it = projeteis.get_primeiro(), p = 0; p < projeteis.getTamanho(); it.operator++(), p++) {
				aux = it.operator*();
				if(aux != nullptr){
					aux->update(dt);
				}
			}
			lancamento++;

			desenhar();

			remover_projeteis();
		}

		void Jogador::mover(float dt)
		{
			aplicarFisica(dt);
			setPosition(position.x + (currentVelocity.x * dt), position.y + currentVelocity.y);
		}

		void Jogador::salvar(nlohmann::ordered_json& entrada)
		{
			salvarPersonagem(entrada);
			entrada["jogador_num"] = Player;
			entrada["olhando_direita"] = facingRight;
			entrada["pontos"] = pontos;
		}

		void Jogador::carregar(nlohmann::ordered_json& saida)
		{
			carregarDadosPersonagem(saida);
			setFacingRight(saida["olhando_direita"].template get<bool>());
			pontos = (saida["pontos"].template get<unsigned int>());
		}

		void Jogador::operator++(int p)
		{
			pontos += p;
		}

		unsigned int Jogador::getPontos()
		{
			return pontos;
		}

		int Jogador::getNumJogadores()
		{
			return numJogadores;
		}

		void Jogador::colidir(Entidades::Entidade* e)
		{
			if (e) {
				if (e->getId() == Entidades::ID::inimigo_raiva || e->getId() == Entidades::ID::inimigo_tristeza) {
					setPosition(position + static_cast<Entidades::Personagens::Personagem*>(e)->getDirection() * 40);
				}
				else if (e->getId() == Entidades::ID::plataforma) {
					isGrounded = true;
					setAtrito(0.25);
				}
			}
		}
		void Jogador::atacar()
		{
			if(lancamento >= FREQUENCIA_TIRO){
				Entidades::Projetil* projetil;
				if (Player == Jogador1) {
					projetil = new Entidades::Projetil("Assets/Sprites/pixie_bubble.png", 3);
				}
				else {
					projetil = new Entidades::Projetil("Assets/Sprites/bytie_bubble.png", 3);
				}
				projetil->setAtirador(this);
				if (facingRight) {
					projetil->setDirection(1, 0);
					projetil->setPosition(position.x + tamanho.x / 2, position.y);
				}
				else {
					projetil->setDirection(-1, 0);
					projetil->setPosition(position.x, position.y);
				}
				projeteis.incluir(projetil);
				lancamento = 0;
			}
		}
		void Jogador::pular()
		{
			if (isGrounded) {
				currentVelocity.y = -jumpSpeed;
				direction.y = 1;
				isGrounded = false;
			}
		}

		void Jogador::aplicarFisica(float dt)
		{
			float velocidadeX = fabs(currentVelocity.x);
			if (velocidadeX < max_vel)
				currentVelocity.x += acceleration * direction.x * dt;

			//gravidade
			position.y += gravityCataliser;
			if (!isGrounded) {
				position.y += gravityCataliser;
				direction.y = -1;
			}
			//atrito
			if (currentVelocity.x > 0.f)
			{
				currentVelocity.x -= atrito * dt;
				if (currentVelocity.x < 0.f)
					currentVelocity.x = 0.f;
			}
			else if (currentVelocity.x < 0.f)
			{
				currentVelocity.x += atrito * dt;
				if (currentVelocity.x > 0.f)
					currentVelocity.x = 0.f;
			}

			//pulo
			if (currentVelocity.y < 0.f && fabs(currentVelocity.y) < ALTURA_PULO / 100)
				currentVelocity.y -= jumpSpeed * dt;

			else if (currentVelocity.y < 0.f) {
				currentVelocity.y += gravidade + gravityCataliser * 2.f;
				direction.y = -1;
				if (currentVelocity.y > 0.f) {
					currentVelocity.y = 0.f;
					direction.y = 0;
				}
			}

			if (direction.y == -1)
				position.y -= gravidade * gravityCataliser;
		}

		void Jogador::remover_projeteis()
		{
			if (projeteis.getTamanho() > 0) {
				Listas::Lista<Entidades::Entidade>::Iterador it = projeteis.get_primeiro();
				Entidades::Entidade* aux = it.operator*();
				int i = 0;

				while (i < projeteis.getTamanho()) {
					aux = it.operator*();
					if (static_cast<Entidades::Projetil*>(aux)->getColidiu()) {
						projeteis.remover(aux);
						projeteis_lancados.push_back(aux);
					}
					it.operator++(); i++;

				}
			}
		}

		bool Jogador::getFacingRight() const
		{
			return facingRight;
		}
		void Jogador::setFacingRight(const bool b)
		{
			facingRight = b;
		}
		bool Jogador::getIsGrounded()
		{
			return isGrounded;
		}
		Listas::ListaEntidades* Jogador::getProjeteis()
		{
			return &projeteis;
		}
		void Jogador::zeraPontos()
		{
			pontos = 0;
		}
	}
}