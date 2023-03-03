#pragma once

class Scene;

class Renderer
{
public:
	// If changed, update AppSettings.h (src/App/AppSettings.h)
	const float SCREEN_WIDTH = 1024.0f;
	const float SCREEN_HEIGHT = 768.0f;

	Renderer();

	void Init(Scene& scene);

	void Update(float deltaTime);
	void Render();

private:

	Scene* m_scene;
};

