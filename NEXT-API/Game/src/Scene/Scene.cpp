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
}

float Scene::GetDeltaTime()
{
	return m_deltaTime;
}

float Scene::GetTime()
{
	return m_time.count();
}

