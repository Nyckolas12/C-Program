#include "Bullets.h"
#include "Engine.h"

void Bullet::OnCollision(Actor* actor)
{
}

void Bullet::Update(float dt)
{
	Particle::Data data
	{
		m_transform.position,
		Vector2{1,0}.Rotate(randomf(Math::TwoPi)) * 50,
		randomf(0.5f,5.0f)


	};

	//m_transform.position.x = Math::Wrap(m_transform.position.x, (float)g_engine.Get)
	m_velocity = Vector2{1,0 }.Rotate(m_transform.rotation) * m_speed;
	Actor::Update(dt);
}
