#include "stdafx.h"
#include "GOActor.h"
#include "../src/Scene/Scene.h"

// ToDo: Come back to constructor
GOActor::GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform)
{
	this->sprite = &sprite;

	this->SetTransform(transform);

	this->scene = &scene;
	
}

void GOActor::Move(MovementDirection direction)
{

	this->sprite->Update(deltaTime);
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
	case MovementDirection::RIGHT:
		//this->sprite->SetAnimation(ANIM_RIGHT);
		this->sprite->GetPosition(x, y);
		x += characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		break;
	case MovementDirection::LEFT:
		//this->sprite->SetAnimation(ANIM_LEFT);
		this->sprite->GetPosition(x, y);
		x -= characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		break;

	}
}

void GOActor::SetCharacterMoveSpeed(float MoveSpeed)
{
	this->characterMoveSpeed = MoveSpeed;
}

void GOActor::HandlePlayerInput()
{
	// ToDo: Two Controllers? Implementation is there but then requires 2 reviewers to play. 
	// ToDo: Allow for both? GameManager does not care how characters are controlled they 
	// are seperate entitiies.
	
	if (App::GetController().GetLeftThumbStickY() > 0.5f)
	{
		Move(MovementDirection::DOWN);
	}
	if (App::GetController().GetLeftThumbStickY() < -0.5f)
	{
		Move(MovementDirection::UP);
	}
	if (App::GetController().GetLeftThumbStickX() > 0.5f)
	{
		Move(MovementDirection::RIGHT);
	}
	if (App::GetController().GetLeftThumbStickX() < -0.5f)
	{
		Move(MovementDirection::LEFT);
	}
	
	// ToDo - Bomb Drop

}

void GOActor::Render()
{
	GameObject::Render();
}

void GOActor::SetDeltaTime(float deltaTime)
{
	this->deltaTime = deltaTime;
}

void GOActor::Destroy()
{
	delete this;
}

