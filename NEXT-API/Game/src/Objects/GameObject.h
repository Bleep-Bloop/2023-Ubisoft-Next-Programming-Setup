#pragma once

#include "../Components/Transform/Transform.h"
#include "../Components/Collider/Collider.h"


/// <summary>
/// GameObjects are items with physical representations in the game world,
/// they feature sprites, transforms, and colliders.
/// </summary>
class GameObject
{
public:

	GameObject(CSimpleSprite& sprite, Transform transform);

	/// <summary>
	/// Sets the GameObject's location, rotation, and scale (changes visible in sprite).
	/// </summary>
	/// <param name="sprite"> Visual representation</param>
	/// <param name="transform"> Location, rotation, and scale (NOTE: scale currently scales the entire sprite based on scale.x)</param>
	void SetTransform(Transform transform);

	/// <summary>
	/// Returns GameObject's transform.
	/// </summary>
	/// <returns>Transform : GameObject's location, rotation, and scale.</returns>
	Transform GetTransform();

	// ToDo: Unique identifier. Creation should be handled in Scene.
	// int ID; // Const? public get private set?

	/// <summary>
	/// Remove GameObject from game.
	/// </summary>
	void Destroy();

protected:

	Transform transform;

	CSimpleSprite* sprite;

	// ToDo: Implement Collision
	// Collider collider;
	// Collider GetCollider();
	// OnHit function()

};

