#pragma once

#include <chrono> // more reliable then glutGet(GLUT_ELAPSED_TIME); ToDo: Note in documentation
#include "../Components/Transform/Transform.h"
#include "../Components/Collider/Collider.h"
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


private:
	// Time
	float m_deltaTime; // Time since last update
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_current;
	std::chrono::duration<float> m_time; // Time passed since beginning of cycle
	
	// Helper Functions
	void SetTime(float deltaTime);

	// Unique ID
	int m_id; // Where this used?

	// TooDo: int CreateId();

	// Component Arrays
	// ToDo :std::vector<GameObject> _gameObjects;

	std::vector<Transform> m_transform;
	std::vector<Collider> m_collider;


	// ToDo: Pause(), GetUI()
	
};

