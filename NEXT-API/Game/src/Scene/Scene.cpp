#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
}

void Scene::Init()
{
}

void Scene::Update(float deltaTime)
{
	SetTime(deltaTime);

	
}

float Scene::GetDeltaTime()
{
	return m_deltaTime;
}

float Scene::GetTime()
{
	return m_time.count();
}

void Scene::SetTime(float deltaTime)
{
	m_deltaTime = deltaTime;
	m_current = std::chrono::steady_clock::now();
	m_time = m_current - m_start;
}
