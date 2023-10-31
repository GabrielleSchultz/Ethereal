#pragma once

#include "Vector2D.h"

//toda entidade que pode se mover dentro do jogo

class DynamicBody
{
protected:
	Math::Vector2Df currentVelocity;
	Math::Vector2Df direction;
	float speed;
	float acceleration;
	float atrito;
	float delta_time;
	float max_vel;

public:
	DynamicBody();
	~DynamicBody();
	void setDeltaTime(const float dt);
	void setupValues();

};

