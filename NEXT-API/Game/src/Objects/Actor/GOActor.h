#pragma once

#include "../GameObject.h"
#include "../../App/SimpleSprite.h"

enum class MovementDirection

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

	GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform);

	/// <summary>
	/// Moves the character in the given direction.
	/// </summary>
	/// <param name="direction"></param>
	void Move(MovementDirection direction);

	void SetCharacterMoveSpeed(float MoveSpeed);

	/// <summary>
	/// Sets animation to be played
	/// </summary>
	// ToDo: void PlayAnimation();
	// Note: I am going to have the animations in the specific characters struct.

private:

	// Used in Move(); // ToDo: Move
	float x, y; 

	float characterMoveSpeed = 1;

};

