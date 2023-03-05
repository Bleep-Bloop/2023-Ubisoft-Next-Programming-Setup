#pragma once

#include "../GameObject.h"
#include "../../App/SimpleSprite.h"


<<<<<<< HEAD
enum class MovementDirection
=======
// enum class preferred because they cause fewer surprises that could potentially lead to bugs.
// enum class enumerator names are local to the enum and their values do not implicitly convert to other types (like another enum or int)
enum class movementDirection
>>>>>>> 0aea93d9bf348c78b119cdf60cbf597a826cb6c0
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
class GOActor : GameObject
{

public:

<<<<<<< HEAD
	GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform);

	// ToDo: Base movement on Character's walk speed;
	/// <summary>
	/// Moves the character in the given direction.
	/// </summary>
	/// <param name="direction"></param>
	void Move(MovementDirection direction);

	void SetCharacterMoveSpeed(float MoveSpeed);
=======
	// transform and all that

	void Move(movementDirection direction);
>>>>>>> 0aea93d9bf348c78b119cdf60cbf597a826cb6c0

	/// <summary>
	/// Sets animation to be played
	/// </summary>
	// ToDo: void PlayAnimation();
	// Note: I am going to have the animations in the specific characters struct.

<<<<<<< HEAD
private:

	// Used in Move(); // ToDo: Move
	float x, y; 

	float characterMoveSpeed = 1;
=======
	// I don't understnad what this is actually for exactly but passing it works so whatever future problem
	float x, y; /// is it bad to place this here? probably right

>>>>>>> 0aea93d9bf348c78b119cdf60cbf597a826cb6c0

};

