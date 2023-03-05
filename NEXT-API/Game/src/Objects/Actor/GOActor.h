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

// enum class preferred because they cause fewer surprises that could potentially lead to bugs.
// enum class enumerator names are local to the enum and their values do not implicitly convert to other types (like another enum or int)
enum class movementDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

/// <summary>
/// GOActor is a GameObject that has built-in movement logic. They are responsible for physical interaction between 
/// Player/AI and the game world.
/// </summary>
class GoActor : GameObject
{

	GoActor(Scene& scene, CSimpleSprite* sprite, Transform transform);

	// transform and all that

	void Move(movementDirection direction);

	/// <summary>
	/// Sets animation to be played
	/// </summary>
	// ToDo: void PlayAnimation();
	// ToDo/Question: Should I create animations in a character class/struct that holds all the information for said character?

	// I don't understnad what this is actually for exactly but passing it works so whatever future problem
	float x, y; /// is it bad to place this here? probably right


};

