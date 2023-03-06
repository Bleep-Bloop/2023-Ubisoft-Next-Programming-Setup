#include "stdafx.h"
#include "GameObject.h"

#include "../Math/Random/RandomUtility.h"

GameObject::GameObject(Scene& scene, CSimpleSprite &sprite, Transform transform) 
{
	// ToDo: Immediately change this. It's just gambling.
	this->uniqueID = RandomUtility::RandomInt(0, 10000);

	this->sprite = &sprite;
	
	this->SetTransform(transform);

	this->scene = &scene;

	this->collider.radius = (this->sprite->GetWidth() / 2); // Derive collision based on sprite size

}

void GameObject::SetTransform(Transform transform)
{
	this->transform = transform;

	this->sprite->SetPosition(this->transform.position.x, this->transform.position.y);
	
	// ToDo: Handle scaling on x and y individually.
	this->sprite->SetScale(this->transform.scale.x);

	// ToDo: Handle rotation on x and y.
	this->sprite->SetAngle(this->transform.rotation.z);
	
}

Transform GameObject::GetTransform() const
{
	return this->transform;
}

Collider GameObject::GetCollider() const
{
	return this->collider;
}

void GameObject::Destroy()
{
	delete this->sprite;
	delete this->scene;
	delete this;
}

void GameObject::Render()
{
	this->sprite->Draw();
}

int GameObject::GetID() const
{
	return uniqueID;
}
