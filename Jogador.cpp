#include "Jogador.h"

#define FREQUENCIA_TIRO 100
#define PLAYER_MAXVEL 4

//jumping
#define DURACAO_PULO 2
#define ALTURA_PULO 128

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
			gravityCataliser(0.6f),
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

		}

		void Jogador::inicializa()
		{
			pControles->setJogador(this);

			if (Player == 2)
			{
				pControles->setKeyCommands("up", "right", "left", "down");
			}

			max_vel = PLAYER_MAXVEL;
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

			if (!isGrounded)
				position.y += 2 * gravityCataliser * dt;
			
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

			if (currentVelocity.y < 0.f) {
				currentVelocity.y += gravidade + gravityCataliser * 4.f;
				if (currentVelocity.y > 0.f)
					currentVelocity.y = 0.f;
			}

			//std::cout << isGrounded << std::endl;
			//std::cout << currentVelocity.y << std::endl;
			setPosition(position.x + (currentVelocity.x * dt), position.y + currentVelocity.y);
		}

		void Jogador::salvar(nlohmann::ordered_json& entrada)
		{
			salvarPersonagem(entrada);
			entrada["jogador_num"] = Player;
			entrada["olhando_direita"] = facingRight;
		}

		void Jogador::carregar(nlohmann::ordered_json& saida)
		{
			carregarDadosPersonagem(saida);
			setFacingRight(saida["olhando_direita"].template get<bool>());
			
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
				// feito com base no vídeo: https://www.youtube.com/watch?v=DZOCzW9e6Qs
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
				float jumpSpeed = sqrtf(2.0f * gravityScale * 0.2 * ALTURA_PULO);
				currentVelocity.y = -jumpSpeed;
				isGrounded = false;
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
	}
}