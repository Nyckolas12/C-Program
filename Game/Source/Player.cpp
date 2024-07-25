#include "Player.h"
#include "Engine.h"
#include "Bullets.h"
#include "Scene.h"
#include "SpaceGame.h"
#include <iostream>

void Player::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Enemy" || actor -> GetTag() == "Alien")
	{
	

	dynamic_cast<SpaceGame*>( m_scene->GetGame())->OnPlayerDeath();

	m_destroyed = true;

	}
}

void Player::Update(float dt)
{	//movement
	float thrust = 0;
	Vector2 direction{ 0,0 };
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_A))  m_transform.rotation -= Math::DegToRad(100) * dt;
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_D)) m_transform.rotation += Math::DegToRad(100) * dt;

	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_S)) direction.x = -1;
	if (g_engine.GetInput().GetKeyDown(SDL_SCANCODE_W)) direction.x = 1;


	Vector2 acceleration = direction.Rotate(m_transform.rotation) * m_speed;
	m_velocity += acceleration * dt;
	
	m_transform.position.x = Math::Wrap(m_transform.position.x, (float)g_engine.GetRenderer().GetWidth());
	m_transform.position.y = Math::Wrap(m_transform.position.y, (float)g_engine.GetRenderer().GetHeight());

	//fire 
	m_fireTimer -= dt;
	if (g_engine.GetInput().GetMouseButtonDown(0) && m_fireTimer <= 0) //&& !g_engine.GetInput().GetPreviousKeyDown(SDL_SCANCODE_SPACE))
	{
		m_fireTimer = 1;

		Vector2 direction = g_engine.GetInput().GetMousePosition() - m_transform.position;
		float angle = direction.Angle();

		std::vector<Vector2> points;
		points.push_back(Vector2{ 5, 0 });
		points.push_back(Vector2{ -5, -5 });
		points.push_back(Vector2{ -5, 5 });
		points.push_back(Vector2{ 5, 0 });

		// actor
		Model* model = new Model{ points, Color{ 1, 1, 0 } };
		Transform transform{ m_transform.position,m_transform.rotation,1.0f };
		
		auto bullet = std::make_unique<Bullet>(600, transform, model);
		bullet->SetLifeSpan(1);
		bullet->SetTag("PlayerBullet");
		m_scene->AddActor(std::move(bullet));
	}

	Actor::Update(dt);
	

}
