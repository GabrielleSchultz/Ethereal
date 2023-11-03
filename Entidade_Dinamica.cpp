#include "Entidade_Dinamica.h"

namespace Entidades {

	Entidade_Dinamica::Entidade_Dinamica(const char* filePath, ID identidade) :
	Entidade (filePath, identidade),
	currentVelocity(0.f, 0.f),
	direction(0.f, 0.f),
	speed(0.f),
	acceleration(0.f),
	atrito(0.f),
	delta_time(0.f),
	max_vel(0.f)
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
	}

}