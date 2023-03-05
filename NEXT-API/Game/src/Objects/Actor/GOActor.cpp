#include "stdafx.h"
#include "GOActor.h"

// ToDo: Come back to constructor
GOActor::GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform)
{
	this->sprite = &sprite;

<<<<<<< HEAD
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
=======
void GoActor::Move(movementDirection direction)
{

	// this->sprite->Update(deltaTime); IMPORTANT I BELIVE THIS HAS TO BE CALLED FOR ANIMATION TO WORK PROPERLY
	// ToDo: Figure out how I want to animatino later.
	// I think I can just sprite->SetAnimation(ANIM_FORWARDS); All GOActors should require an animation. I am unsure what happens if they don't I think it will still be fine.
	switch (direction)
	{
	default:
		// this->sprite->SetAnimation(-1); -1 pauses I wonder what 0 does I assume default. 
		break;
	case movementDirection::UP:
		//this->sprite->SetAnimation(ANIM_FORWARDS);
		this->sprite->GetPosition(x, y); // What does this do exactly? I see it returns but I don't really understand how. SimpleSprite line 27
		y += 1.0f;
		this->sprite->SetPosition(x, y);
		// I set the posistion when I make them. then I guess this goes after this
		// IMPORTRANT NOTE-MAKE SURE POSISTION IS SET!!!
		break;
	case movementDirection::DOWN:
		// sprite->SetAnimation(ANIM_BACKWARDS);
		this->sprite->GetPosition(x, y);
		y -= 1.0f;
		this->sprite->SetPosition(x, y);
		break;
	case movementDirection::LEFT:
		//this->sprite->SetAnimation(ANIM_LEFT);
		this->sprite->GetPosition(x, y);
		x -= 1.0f;
		this->sprite->SetPosition(x, y);
		break;
	case movementDirection::RIGHT:
		//this->sprite->SetAnimation(ANIM_RIGHT);
		float x, y;
		this->sprite->GetPosition(x, y);
		x += 1.0f;
>>>>>>> 0aea93d9bf348c78b119cdf60cbf597a826cb6c0
		this->sprite->SetPosition(x, y);
		break;

	}


}
<<<<<<< HEAD

void GOActor::SetCharacterMoveSpeed(float MoveSpeed)
{
	this->characterMoveSpeed = MoveSpeed;
}
=======
>>>>>>> 0aea93d9bf348c78b119cdf60cbf597a826cb6c0
