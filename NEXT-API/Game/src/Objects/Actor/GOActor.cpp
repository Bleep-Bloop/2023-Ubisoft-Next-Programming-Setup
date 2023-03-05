#include "stdafx.h"
#include "GOActor.h"

// ToDo: Come back to constructor
GOActor::GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform)
{
	this->sprite = &sprite;

	this->SetTransform(transform);

	this->scene = &scene;
}

void GOActor::Move(MovementDirection direction)
{
	// Note: Make sure to set posistion when creating sprite to set the values properly.
	// this->sprite->Update(deltaTime); // Important! Call here after putting Move in Tick()
	switch (direction)
	{
	default:
		// this->sprite->SetAnimation(-1); ToDo: Check if 0 is default, -1 is pause.
		break;
	case MovementDirection::UP:
		//this->sprite->SetAnimation(ANIM_FORWARDS);
		this->sprite->GetPosition(x, y); // What does this do exactly? I see it returns but I don't really understand how. SimpleSprite line 27
		y += characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		break;
	case MovementDirection::DOWN:
		// sprite->SetAnimation(ANIM_BACKWARDS);
		this->sprite->GetPosition(x, y);
		y -= characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		break;
	case MovementDirection::LEFT:
		//this->sprite->SetAnimation(ANIM_LEFT);
		this->sprite->GetPosition(x, y);
		x -= characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		break;
	case MovementDirection::RIGHT:
		//this->sprite->SetAnimation(ANIM_RIGHT);
		float x, y;
		this->sprite->GetPosition(x, y);
		x += characterMoveSpeed;
	}
}

void GOActor::SetCharacterMoveSpeed(float MoveSpeed)
{
	this->characterMoveSpeed = MoveSpeed;
}

