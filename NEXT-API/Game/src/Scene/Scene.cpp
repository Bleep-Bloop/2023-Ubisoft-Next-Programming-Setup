#include "stdafx.h"
#include "Scene.h"
#include "../Character/Character.h"
#include <vector>
Scene::Scene() : m_deltaTime(0.0f)
{

	// Initialize Time Variables
	m_start = std::chrono::steady_clock::now();
	m_current = m_start;
	m_time = m_current - m_start;
	
}

void Scene::Init()
{

	// ToDo: If out of dev time generate level here./

	// Quick character creation to test functionality
	TestCreateGOActors();

}

void Scene::Update(float deltaTime)
{

	SetTime(deltaTime);
	for (auto& id : m_actors) 
	{
		//id->HandlePlayerInput();
		id->PhysicsMove(deltaTime);
		id->CheckCollision(*this);
	}

}

float Scene::GetTime() const
{
	return m_time.count();
}

float Scene::GetDeltaTime() const
{
	return m_deltaTime;
}

void Scene::SetTime(float deltaTime)
{
	m_deltaTime = deltaTime;
	m_current = std::chrono::steady_clock::now();
	m_time = m_current - m_start;
}


// // This is just for testing. I call it inside Init() to make characters.
// Quick Testing ToDo: Handle in level/game manager/system.
GOActor* madeCharacter;
GOActor* madeCharacter2;
void Scene::TestCreateGOActors()
{

	CSimpleSprite* characterSprite = App::CreateSprite(".\\Data\\steambot_03.bmp", 5, 1);
	characterSprite->SetPosition(400, 400);
	Transform characterTransform;
	characterTransform.position = Vector3(400, 400, 0);

	madeCharacter = new GOActor(*this, *characterSprite, characterTransform);
	m_actors.push_back(madeCharacter);


	CSimpleSprite* characterSprite2 = App::CreateSprite(".\\Data\\steambot_03.bmp", 5, 1);
	characterSprite2->SetPosition(500, 400); // Be Aware of sprite->SetPosistion vs Transform.position.
	characterTransform.position = Vector3(500, 400, 0);

	madeCharacter2 = new GOActor(*this, *characterSprite2, characterTransform);
	madeCharacter2->canMove = false; // Need to disable one to test collision
	m_actors.push_back(madeCharacter2);


}

















void Scene::Render()
{
	madeCharacter->Render();
	madeCharacter2->Render();
}

// Vectors
void Scene::AddActor(GOActor* actor)
{
	m_actors.push_back(actor);
}

void Scene::AddObject(GameObject* object)
{
	m_objects.push_back(object);
}




/*
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
*/




