#include "Entidade_Dinamica.h"

#define ATRITO_DEFAULT 0.5f
#define MAXVEL_DEFAULT 7.5f
#define ACELERACAO_DEFAULT 0.25f


namespace Entidades {
	namespace Tipo {

		Tipo::Dinamica::Dinamica() :
			currentVelocity(0.f, 0.f),
			direction(0.f, 0.f),
			speed(0.f),
			acceleration(0.5f),
			atrito(0.25f),
			delta_time(0.f),
			max_vel(7.5f)
		{
			setupValues();
		}

		Tipo::Dinamica::~Dinamica()
		{
		}

		void Tipo::Dinamica::setDeltaTime(const float dt)
		{
			delta_time = dt;
		}

		void Tipo::Dinamica::setupValues()
		{
			max_vel = 7.5f;
			acceleration = 0.5f;
			setAtrito(0.25f);
		}

		float Tipo::Dinamica::getAtrito() const
		{
			return atrito;
		}

		void Tipo::Dinamica::setAtrito(const float at)
		{
			atrito = at;
		}

		Math::Vector2Df Tipo::Dinamica::getDirection() const
		{
			return direction;
		}

		void Dinamica::salvarAtributosDinamicos(nlohmann::ordered_json& entrada)
		{
			entrada["atrito"] = atrito;
			entrada["direcao"] = { {"x", direction.x}, {"y", direction.y } };
			entrada["velocidade"] = { {"x", direction.x}, {"y", direction.y } };
		}

		void Tipo::Dinamica::setDirection(const Math::Vector2Df direcao)
		{
			direction = direcao;
		}

		void Tipo::Dinamica::setDirection(float x, float y)
		{
			direction.x = x;
			direction.y = y;
		}
		void Dinamica::setVelocidade(float x, float y)
		{
			currentVelocity.x = x;
			currentVelocity.y = y;
		}
	}
}