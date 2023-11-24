#pragma once

#include "Vector2D.h"
#include "json.h"

//toda entidade que pode se mover dentro do jogo

namespace Entidades {
	class Entidade;
	namespace Tipo {
		class Dinamica
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
			Dinamica();
			~Dinamica();
			//sets
			void setDeltaTime(const float dt);
			void setupValues();
			void setAtrito(const float at);
			void setDirection(const Math::Vector2Df direcao);
			void setDirection(float x, float y);
			void setVelocidade(float x, float y);
			//gets
			float getAtrito() const;
			Math::Vector2Df getDirection() const;
			//move
			virtual void colidir(Entidades::Entidade* e) = 0;
			virtual void update(float dt) = 0;
			virtual void mover(float dt) {}
			void salvarAtributosDinamicos(nlohmann::ordered_json& entrada);
			virtual void salvar(nlohmann::ordered_json& entrada) = 0;

		};
	}
}