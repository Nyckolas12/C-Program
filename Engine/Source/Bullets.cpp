#include "Bullets.h"

void Bullet::OnCollision(Actor* actor)
{
}

void Bullet::Update(float dt)
{
	m_velocity = Vector2{1,0 }.Rotate(m_transform.rotation) * m_speed;
	Actor::Update(dt);
}
