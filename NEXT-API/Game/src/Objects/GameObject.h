#pragma once

#include "../Components/Transform/Transform.h"
#include "../Components/Collider/Collider.h"

// ToDo: ChangeSprite() & ChangeCollider() 

/// <summary>
/// GameObjects are items with physical representations in the game world,
/// they contain sprites, transforms, and colliders.
/// </summary>
class GameObject
{
public:
	
	GameObject(Scene &scene, CSimpleSprite &sprite, Transform transform);

	GameObject() = default;

	/// <summary>
	/// Sets the GameObject's location, rotation, and scale (changes visible in sprite).
	/// </summary>
	/// <param name="sprite"> Visual representation</param>
	/// <param name="transform"> Location, rotation, and scale (NOTE: scale currently scales the entire sprite based on scale.x)</param>
	virtual void SetTransform(Transform transform);

	virtual Transform GetTransform() const;

	virtual Collider GetCollider() const;

	virtual int GetID() const;

	/// <summary>
	/// Draws the GameObject sprite.
	/// IMPORTANT - Must be called from Game.cpp->Render().
	/// </summary>
	virtual void Render();

	/// <summary>
	/// Remove GameObject from game.
	/// </summary>
	virtual void Destroy();

protected:

	Transform transform;

	CSimpleSprite* sprite;

	Collider collider;
	
	Scene* scene;

	// Identifying number assigned on construction ToDo: *
	int uniqueID;

};

