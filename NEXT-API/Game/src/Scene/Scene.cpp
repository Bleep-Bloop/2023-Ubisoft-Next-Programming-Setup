#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{

	// Initialize Time Variables
	m_start = std::chrono::steady_clock::now();
	m_current = m_start;
	m_time = m_current - m_start;


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

Transform Scene::GetTransform(int id) const
{
	return m_transform[id];
}

void Scene::SetTransform(int id, Transform transform)
{
	m_transform[id] = transform;
}

void Scene::SetTime(float deltaTime)
{
	m_deltaTime = deltaTime;
	m_current = std::chrono::steady_clock::now();
	m_time = m_current - m_start;
}
