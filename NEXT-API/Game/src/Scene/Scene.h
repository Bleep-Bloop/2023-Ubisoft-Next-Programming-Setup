#pragma once

#include <chrono> // more reliable then glutGet(GLUT_ELAPSED_TIME); ToDo: Note in documentation
#include "../Components/Transform/Transform.h"
#include "../Components/Collider/Collider.h"
#include "../src/Objects/Actor/GOActor.h"
#include "../Objects/GameObject.h"


struct Vector3;

class Scene
{
public: 
	Scene();

	void Init(); // ToDo: Finish initializer &Renderer and &UI. Initialize m_deltaTime(0)

	void Update(float deltaTime);

	float GetDeltaTime();

	float GetTime();

	Transform GetTransform(int id) const;

	void SetTransform(int id, Transform transform);

	Collider GetCollider(int id) const;
	 
	void SetCollider(int id, Collider collider);



	// Trak Time
	float m_deltaTime; // Time since last update
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_current;
	std::chrono::duration<float> m_time; // Time passed since beginning of cycle
	
	// Helper Functions
	void SetTime(float deltaTime);

	// Unique ID
	int m_id; // Where this used?

	// ToDo: int CreateId();

	// Component Arrays
	// ToDo :std::vector<GameObject> _gameObjects;

	std::vector<Transform> m_transform;
	std::vector<Collider> m_collider;
	
	std::vector<GOActor> m_actors;
	
	
	// ToDo: Best place to call this? I like in the constructor but also feels wrong.
	/// <summary>
	/// Adds GOActor into m_actors vector.
	/// </summary>
	void AddActor(GOActor &actor); // Agh more new. Maybe just leave note about the object pool planned changes if don't get there.


	// Gameplay Logic
	// System m_system

	
	// ToDo: Pause(), GetUI()

	
};

