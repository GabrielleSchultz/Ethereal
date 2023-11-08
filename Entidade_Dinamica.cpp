#include "Entidade_Dinamica.h"

#define ATRITO_DEFAULT 0.5f
#define MAXVEL_DEFAULT 7.5f
#define ACELERACAO_DEFAULT 0.25f


namespace Entidades {

	Entidade_Dinamica::Entidade_Dinamica(const char* filePath, ID identidade) :
	Entidade (filePath, identidade),
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

	Entidade_Dinamica::~Entidade_Dinamica()
	{
	}

	void Entidade_Dinamica::setDeltaTime(const float dt)
	{
		delta_time = dt;
	}

	void Entidade_Dinamica::setupValues()
	{
		max_vel = 7.5f;
		acceleration = 0.5f;
		setAtrito(0.25f);
	}

	float Entidade_Dinamica::getAtrito() const
	{
		return atrito;
	}

	void Entidade_Dinamica::setAtrito(const float at)
	{
		atrito = at;
	}

	Math::Vector2Df Entidade_Dinamica::getDirection() const
	{
		return direction;
	}

	void Entidade_Dinamica::setDirection(const Math::Vector2Df direcao)
	{
		direction = direcao;
	}

}