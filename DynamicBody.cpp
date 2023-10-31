#include "DynamicBody.h"

DynamicBody::DynamicBody():
	currentVelocity(0.f,0.f),
	direction(0.f,0.f),
	speed(0.f),
	acceleration(0.f),
	atrito(0.f),
	delta_time(0.f),
	max_vel(0.f)
{
	setupValues();
}

DynamicBody::~DynamicBody()
{
}

void DynamicBody::setDeltaTime(const float dt)
{
	delta_time = dt;
}

void DynamicBody::setupValues()
{
}
