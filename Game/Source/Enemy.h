#pragma once
#include "Actor.h"
class Enemy : public Actor
{
public:
	Enemy() = default;
	Enemy(const Transform& transform) : Actor{ transform } {}
	Enemy(const Transform& transform, Model* model) :
		Actor{ transform , model }
	{}
	Enemy(float speed, const Transform& transform, Model* model) :
		Actor{ transform , model },
		m_speed{ speed }
	{}
	virtual void OnCollision(Actor* actor);
	void Update(float dt);
	void ApplyForce(const Vector2& force);
	
private:
	float m_speed = 0;
	float m_fireTimer = 0;
	float pushFactor = 0;
};