#pragma once

#include <chrono> // more reliable then glutGet(GLUT_ELAPSED_TIME); ToDo: Note in documentation
class Vector3;

class Scene
{
public: 
	Scene();

	void Init(); // ToDo: Finish initializer &Renderer and &UI

	void Update(float deltaTime);

	float GetDeltaTime();

	float GetTime();

private:
	// Time
	float m_deltaTime; // time since last update
	std::chrono::time_point<std::chrono::steady_clock> m_start;
	std::chrono::time_point<std::chrono::steady_clock> m_current;
	std::chrono::duration<float> m_time; // time passed since beginning of cycle
	
	// Helper Functions
	void SetTime(float deltaTime);



	// ToDo: Pause(), GetUI()
};

