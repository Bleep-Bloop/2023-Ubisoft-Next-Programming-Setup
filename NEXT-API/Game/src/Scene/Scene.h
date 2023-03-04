#pragma once

#include <chrono> // more reliable then glutGet(GLUT_ELAPSED_TIME); ToDo: Note in documentation
#include "../Components/Transform/Transform.h"

class Vector3;

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


private:
	// Time
	float m_deltaTime; // Time since last update
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_current;
	std::chrono::duration<float> m_time; // Time passed since beginning of cycle
	
	// Helper Functions
	void SetTime(float deltaTime);

	// Component Arrays
	std::vector<Transform> m_transform;


	// ToDo: Pause(), GetUI()
	
};

