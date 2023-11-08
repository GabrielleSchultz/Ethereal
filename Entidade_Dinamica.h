#pragma once

#include "Entidade.h"
#include "Vector2D.h"

//toda entidade que pode se mover dentro do jogo

namespace Entidades {
	class Entidade_Dinamica : public Entidade
	{
	protected:
		Math::Vector2Df currentVelocity;
		Math::Vector2Df direction;
		const float speed;
		float acceleration;
		float atrito;
		float delta_time;
		float max_vel;

	public:
		Entidade_Dinamica(const char* filePath = "", ID identidade = ID::vazio);
		~Entidade_Dinamica();
		//sets
		void setDeltaTime(const float dt);
		void setupValues();
		void setAtrito(const float at);
		void setDirection(const Math::Vector2Df direcao);
		//gets
		float getAtrito() const;
		Math::Vector2Df getDirection() const;
		//move
		void update(float dt) = 0;
		virtual void mover(float dt){}

		virtual void salvar(std::ostringstream* entrada) = 0;

	};

}