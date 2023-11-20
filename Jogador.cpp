#include "Jogador.h"

#define FREQUENCIA_TIRO 100

int Entidades::Personagens::Jogador::numJogadores(0);
int Entidades::Personagens::Jogador::pontos(0);

namespace Entidades {

	namespace Personagens {
		Jogador::Jogador(int nv, const char* texturePath, JogadorNum player, ID id) :
			Personagem(nv, texturePath, id),
			isGrounded(false),
			isJumping(false),
			Player(player),
			jumpPressedRemember(0.f),
			groundedRemember(0.f),
			groundedRememberTimer(0.2f),
			jumpPressedRememberTimer(0.2f),
			gravityCataliser(0.5f),
			lancamento(FREQUENCIA_TIRO),
			facingRight(true)
		{
			pControles = new Controle::ControleJogador();
			numJogadores++;
			inicializa();
		}

		Jogador::~Jogador()
		{
		}

		void Jogador::inicializa()
		{
			pControles->setJogador(this);

			if (Player == 2)
			{
				pControles->setKeyCommands("up", "right", "left", "down");
			}
		}

		void Jogador::update(float dt)
		{
			mover(dt);
			//projeteis.executar(dt);
			Listas::Lista<Entidades::Entidade>::Iterador it;
			Entidades::Entidade* aux = nullptr;
			int p = 0;
			for (it = projeteis.get_primeiro(), p = 0; p < projeteis.getTamanho(); it.operator++(), p++) {
				aux = it.operator*();
				if(aux){
					aux->update(dt);
				}
			}
			lancamento++;
			desenhar();
		}

		void Jogador::mover(float dt)
		{
			float velocidadeX = fabs(currentVelocity.x);

			if (velocidadeX < max_vel)
				currentVelocity.x += acceleration * direction.x * dt;

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

			setPosition(position.x + (currentVelocity.x * dt), position.y);
		}

		void Jogador::salvar(std::ostringstream* entrada)
		{
			if (!entrada) {
				std::cout << "N�o foi poss�vel abrir o arquivo de salvamento Jogador" << std::endl;
				return;
			}			
			//(*entrada) << _id << id << std::endl;
			//(*entrada) << getId() << position.x << std::endl << position.y << std::endl << num_vidas << std::endl << pontos << std::endl << facingRight << std::endl;
		}

		void Jogador::operator++(int p)
		{
			pontos += p;
		}

		const int Jogador::getPontos()
		{
			return pontos;
		}

		int Jogador::getNumJogadores()
		{
			return numJogadores;
		}
		void Jogador::colidir(Entidades::Entidade* e)
		{
			if(e){
				if (e->getId() == Entidades::ID::inimigo_raiva) {
					// arrumar pra quando colis�o � na direita !! 
					setPosition(position.x - 50, position.y);
				}
				if (e->getId() == Entidades::ID::plataforma) {
					setAtrito(0.25f);
				}
			}
		}
		void Jogador::atacar()
		{
			if(lancamento >= FREQUENCIA_TIRO){
				// feito com base no v�deo: https://www.youtube.com/watch?v=DZOCzW9e6Qs
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
		bool Jogador::getFacingRight() const
		{
			return facingRight;
		}
		void Jogador::setFacingRight(const bool b)
		{
			facingRight = b;
		}
		Listas::ListaEntidades* Jogador::getProjeteis()
		{
			return &projeteis;
		}
	}
}