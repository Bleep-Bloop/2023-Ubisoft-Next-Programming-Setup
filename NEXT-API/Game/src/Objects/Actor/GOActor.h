#pragma once

#include "../GameObject.h"

enum class MovementDirection

{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	STATIONARY,
};

/// <summary>
/// GOActor is a GameObject that has built-in movement logic. They are responsible for physical interaction between 
/// Player/AI and the game world.
/// </summary>
class GOActor :  GameObject
{

public:

	GOActor(Scene& scene, CSimpleSprite& sprite, Transform transform);

	// ToDo: Implement AI
	/// <summary>
	/// Moves the character in the given direction.
	/// This one is used for AI control. It doesn't have the functionality to deal with wall collisions
	/// like PhysicsMove() for the player does.
	/// </summary>
	/// <param name="direction"></param>
	void Move(MovementDirection direction);

	void PhysicsMove(float deltaTime);

	void SetCharacterMoveSpeed(float MoveSpeed);

	// ToDo: void PlayAnimation();
	// Note: I am going to have the animations in the specific characters struct.

	/// <summary>
	/// Passes input from the player to the GOActor
	/// Note: Called from scene->Update();
	/// </summary>
	void HandlePlayerInput();

	void Render() override;

	void SetDeltaTime(float time);

	void Destroy() override;

	void CheckCollision(Scene& scene);

	bool canMove = true;

private:

	// Sprite x, y coordinates ToDo: Rename
	float x, y; 

	float characterMoveSpeed = 1;

	float deltaTime = 0;

	Vector3 movementVector;
	
	Transform newMovementTransform;
	
	bool actorCollision;
	
	int previousCollisionID;

};

