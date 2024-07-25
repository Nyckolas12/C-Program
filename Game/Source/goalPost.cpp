#include "goalPost.h"
#include "Player.h"
#include "Scene.h"

void goalPost::OnCollision(Actor* actor)
{
    
    if (actor->GetTag() == "Player") 
    {
        dynamic_cast<Player*> (actor)->SetSpeed(900.0f);
    }
   

}

void goalPost::Update(float dt)
{
    Actor::Update(dt);

    
}
