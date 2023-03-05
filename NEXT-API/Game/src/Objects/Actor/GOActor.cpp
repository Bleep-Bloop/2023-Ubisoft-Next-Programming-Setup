#include "stdafx.h"
#include "GOActor.h"


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
		this->sprite->SetPosition(x, y);
		break;

	}


}
