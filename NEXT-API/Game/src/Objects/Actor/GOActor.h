#pragma once

#include "../GameObject.h"
#include "../../App/SimpleSprite.h"

/////struct sAnimation; // Handle this in the character class then just pass it to 
/*{
	unsigned int m_id;
	float m_speed;
	std::vector<int> m_frames;
};
*/


/// <summary>
/// GOActor is a GameObject that has built-in movement logic. They are responsible for physical interaction between 
/// Player/AI and the game world.
/// </summary>
class GoActor : GameObject
{

	GoActor(Scene& scene, CSimpleSprite* sprite, Transform transform);



	/// <summary>
	/// Sets animation to be played
	/// </summary>
	// ToDo: void PlayAnimation();
	// ToDo/Question: Should I create animations in a character class/struct that holds all the information for said character?


};

