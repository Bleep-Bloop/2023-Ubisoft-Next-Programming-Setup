#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(Scene& scene, CSimpleSprite &sprite, Transform transform)
{

	this->sprite = &sprite;
	
	this->SetTransform(transform);

	this->scene = &scene;

	// ToDo: Add to scene's GameObject vector. existingGameObjects.push_back(this); 

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

Transform GameObject::GetTransform()
{
	return this->transform;
}

void GameObject::Destroy()
{
	delete this;
}

void GameObject::Render()
{
	this->sprite->Draw();
}
