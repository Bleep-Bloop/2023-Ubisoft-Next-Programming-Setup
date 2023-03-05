#include "stdafx.h"
#include "Scene.h"


Scene::Scene() : m_deltaTime(0.0f), m_id(0) 
{

	// Initialize Time Variables
	m_start = std::chrono::steady_clock::now();
	m_current = m_start;
	m_time = m_current - m_start;

	
}

void Scene::Init()
{

	// ToDo: If out of time generate level here 

}

void Scene::Update(float deltaTime)
{
	SetTime(deltaTime);

	for (auto& id : m_actors)
	{
		// where arrow go
		id.HandlePlayerInput();
	}

	// On creation I should add
	//for (auto &id : m_actors)
	//{
		// this way looks ok
		// id->HandleInput
	//}

}


void Scene::SetTime(float deltaTime)
{
	m_deltaTime = deltaTime;
	m_current = std::chrono::steady_clock::now();
	m_time = m_current - m_start;
}


void Scene::AddActor(GOActor &actor)
{
	m_actors.push_back(actor);
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

Collider Scene::GetCollider(int id) const
{
	return m_collider[id];
}

void Scene::SetCollider(int id, Collider collider)
{
	m_collider[id] = collider;
}

