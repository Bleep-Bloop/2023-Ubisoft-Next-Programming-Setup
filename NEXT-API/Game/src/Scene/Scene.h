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

	float GetDeltaTime() const;

	float GetTime() const;

	void SetTime(float deltaTime);

	// Component Arrays
	std::vector<GOActor*> m_actors;
	std::vector<GameObject*> m_objects;
	
	// ToDo: Clean up unique ID system.
	//std::vector<int> m_IDs;
	// ToDo: int CreateId();

	// ToDo: Ensure nothing is being added twice.
	// ToDo: Add in constructor. Scene is passed so it's accessible.
	/// <summary>
	/// Adds created GOActor into m_actors vector.
	/// </summary>
	void AddActor(GOActor* actor); 

	/// <summary>
	/// Adds created GameObject into m_objects vector.
	/// </summary>
	/// <param name="object"></param>
	void AddObject(GameObject* object);
	
	/// <summary>
	/// Called from Game.cpp to draw sprites.
	/// </summary>
	void Render();

	// ToDo: Gameplay Manager
	// GameplayManager m_gameManager

	// ToDo: Pause(), GetUI()

private:

	// Handle Time
	float m_deltaTime; // Time since last update
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_current;
	std::chrono::duration<float> m_time; // Time passed since beginning of cycle

	// Debug
	// Used to create player characters before GameManager was implemented
	void TestCreateGOActors();

};

