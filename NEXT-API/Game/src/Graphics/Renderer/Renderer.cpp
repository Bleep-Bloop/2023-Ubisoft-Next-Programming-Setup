#include "stdafx.h"
#include "Renderer.h"

#include "../src/Scene/Scene.h"


Renderer::Renderer() : m_scene(nullptr)
{
}

void Renderer::Init(Scene &scene)
{
	m_scene = &scene;
}

void Renderer::Update(float deltaTime)
{
}

void Renderer::Render()
{
}
