#include "PickUp.h"
#include "Player.h"

void PickUp::OnCollision(Actor* actor)
{
	if (actor->GetTag() == "Player")
	{
		dynamic_cast<Player*> (actor)->SetFireModifier(1.5f);
		m_destroyed = true;
	}
}
