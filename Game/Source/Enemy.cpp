#include "Enemy.h"
#include "Player.h"
#include "Scene.h"
#include "Game.h"
#include "Bullets.h"
#include"Player.h"

void Enemy::OnCollision(Actor* actor)
{
	if(actor->GetTag() == "Player" || actor->GetTag() == "PlayerBullet")
	{
		m_scene->GetGame()->AddPoints(100);
		m_destroyed = true;
	
		// m_destroyed = true;
	}
	
		
	

}
void Enemy::Update(float dt)
{
	Player* player = m_scene->GetActor<Player>();
	if(player)
	{
		Vector2 direction = player->GetTransform().position - m_transform.position;
		m_velocity = direction.Normalized() * m_speed * dt;

		m_transform.rotation = direction.Angle();
	}

	Actor::Update(dt);

}

void Enemy::ApplyForce(const Vector2& force)
{
	pushFactor = 1.0f;

	m_velocity += force * pushFactor;
}
