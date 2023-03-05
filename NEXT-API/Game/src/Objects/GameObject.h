#pragma once

#include "../Components/Transform/Transform.h"
#include "../Components/Collider/Collider.h"
#include "../Scene/Scene.h"

	// ToDo: ChangeSprite() (Calls ChangeCollider() as well)
	// ToDo: Change Collider()
	// ToDo: I don't like creating sprite outside. I could handle testSprite = App::CreateSprite("..\..\data\steambot_03.bmp", 5, 1) 
	//	in a function here to keep project clean
	// ToDo: Handle this in Scene. static std::vector<GameObject*> allGameObjects; Scene reference in constructor to push_back.
	// ToDo: Implement Collision
	// ToDo: Collider collider;
	// ToDo: Collider GetCollider();
	// ToDo: OnHit function()
	// ToDo: Unique identifier. Creation should be handled in Scene.
	// ToDo:int ID; // Const? public get private set?

/// <summary>
/// GameObjects are items with physical representations in the game world,
/// they feature sprites, transforms, and colliders.
/// </summary>
class GameObject
{
public:
	
	GameObject(Scene& scene, CSimpleSprite& sprite, Transform transform);

	GameObject() = default; 

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

	/// <summary>
	/// Remove GameObject from game.
	/// </summary>
	void Destroy();

	/// <summary>
	/// Draws the GameObject sprite.
	/// IMPORTANT - Must be called from Game.cpp->Render().
	/// </summary>
	void Render();

protected:

	Transform transform;

	CSimpleSprite* sprite;
	
	Scene* scene;

};

