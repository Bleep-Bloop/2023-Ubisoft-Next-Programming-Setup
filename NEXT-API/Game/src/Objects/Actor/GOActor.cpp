#include "stdafx.h"
#include "GOActor.h"
#include "../src/Scene/Scene.h"

#include "../src/Math/Random/RandomUtility.h"
#include "../src/Math/Vector3/Vector3.h" // is this the problem?



GOActor::GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform) : x(0), y(0)
{
	// ToDo: Immediately change this. It's just gambling.
	this->uniqueID = RandomUtility::RandomInt(0, 10000);

	this->sprite = &sprite;

	this->SetTransform(transform);

	this->scene = &scene;

	this->collider.radius = (this->sprite->GetWidth() / 2); // Derive collision based on sprite size

}

// Note: Move is built for every character to have the required animations.
// I did not have the time to get/make them all
void GOActor::Move(MovementDirection direction)
{

	this->sprite->Update(deltaTime); // Necessary for animations to play

	switch (direction)
	{
	default:
		// this->sprite->SetAnimation(-1); ToDo: Check if 0 is default. -1 is pause.
		break;
	case MovementDirection::STATIONARY:
		this->sprite->GetPosition(x, y);
		this->sprite->SetPosition(x, y);
		break;
	case MovementDirection::UP:
		//this->sprite->SetAnimation(ANIM_FORWARDS);
		this->sprite->GetPosition(x, y); 
		y += characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		this->transform.position.y += characterMoveSpeed; // change Transform on movement
		break;
	case MovementDirection::DOWN:
		// sprite->SetAnimation(ANIM_BACKWARDS);
		this->sprite->GetPosition(x, y);
		y -= characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		this->transform.position.y -= characterMoveSpeed; // change Transform on movement
		break;
	case MovementDirection::RIGHT:
		//this->sprite->SetAnimation(ANIM_RIGHT);
		this->sprite->GetPosition(x, y);
		x += characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		this->transform.position.x += characterMoveSpeed; // change Transform on movement
		break;
	case MovementDirection::LEFT:
		//this->sprite->SetAnimation(ANIM_LEFT);
		this->sprite->GetPosition(x, y);
		x -= characterMoveSpeed;
		this->sprite->SetPosition(x, y);
		this->transform.position.x -= characterMoveSpeed; // change Transform on movement
		break;
	}
	
}

void GOActor::PhysicsMove(float time)
{

	// Physics Movement Explained
	// Take current transform.position - (0, 0, 0)
	// Store user input as a movement vector - up & right = (1, 1, 0)
	// Next add those vectors and assign to movementVector - movementVector = (0, 0, 0,) + (1, 1, 0) = (1, 1, 0)
	// Then we multiply that by deltaTime and the characters movespeed - (1, 1, 0) * deltaTime * movementSpeed
	// Then we set our transform to newLocation - this->SetTransform(newLocation);


	// WARNING: Circle colliders can cause issues with blending into walls.
	// ToDo: Square Colliders

	// Note/ToDo: Could be a cool character mechanic, force player to slide around on ice.
	// Clear movement vector to prevent slippery/ice feeling.
	
	movementVector = Vector3::Zero;
	
	if (canMove)
	{

		if (App::GetController().GetLeftThumbStickX() > 0.5)
		{
			movementVector += Vector3::Right;
		}
		if (App::GetController().GetLeftThumbStickX() < -0.5)
		{
			movementVector += Vector3::Left;
		}
		if (App::GetController().GetLeftThumbStickY() > 0.5)
		{
			movementVector += Vector3::Down;
		}
		if (App::GetController().GetLeftThumbStickY() < -0.5)
		{
			movementVector += Vector3::Up;
		}

	}
	if (actorCollision == true)
	{
		
		newMovementTransform = this->transform;
		
		if (movementVector.x > 0)
		{
			newMovementTransform.position.x -= 2;
		}
		else if (movementVector.x < 0)
		{
			newMovementTransform.position.x += 2;
		}
		if (movementVector.y > 0)
		{
			newMovementTransform.position.x -= 2;
		}
		else if (movementVector.y > 0)
		{
			newMovementTransform.position.x += 2;
		}
		
		this->SetTransform(newMovementTransform);
		actorCollision = false;
		movementVector = Vector3::Zero;
		
	}
	else
	{
		// Continue normally
		newMovementTransform.position = this->transform.position + movementVector * (time / 15) * 2;
		this->SetTransform(newMovementTransform);
	}

}


void GOActor::SetCharacterMoveSpeed(float MoveSpeed)
{
	this->characterMoveSpeed = MoveSpeed;
}

void GOActor::HandlePlayerInput() // I believe this could be const
{

	// ToDo: Two Controllers? Implementation is there but then requires 2 reviewers to play. 
	// ToDo: Allow for both? GameManager does not care how characters are controlled they 
	// are seperate entitiies.
	
	if (canMove == true)
	{

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
		if (App::GetController().CheckButton(XINPUT_GAMEPAD_A, false)) // DEBUG: Currently Space Bar
		{
			// ToDo: Bomb Drop
		}
	}

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


void GOActor::CheckCollision(Scene& scene)
{

	for (auto& actors : scene.m_actors)
	{

		// ToDo: This collision needs to be reworked. If you continously walk into a wall it will eventually let you walk in.
		if (actors->uniqueID != this->uniqueID && actors->uniqueID != previousCollisionID || this->uniqueID || previousCollisionID)      
		{

			if (Collider::IsHit(scene, this->uniqueID, this->transform, this->collider, actors->uniqueID, actors->GetTransform(), actors->GetCollider())) 
			{
				// Collision
				actorCollision = true;
				previousCollisionID = actors->uniqueID;
			}
			else
			{
				// No Collision
			}
		}
		else
		{
			// Same Actor
		}
	
	}

}

