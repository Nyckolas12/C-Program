#pragma once
#include "Actor.h"
#include "ETime.h"


class goalPost : public Actor
{
public:

	goalPost() = default;
	goalPost(const Transform& transform) : Actor{ transform } {}
	goalPost(const Transform& transform, Model* model) :
		Actor{ transform , model }
	{}
	void OnCollision(Actor* actor) override;

	void Update(float dt);

private:
	bool boostActive = false;
	Time boostTimer;
	float boostDuration = 3.0f;
};

