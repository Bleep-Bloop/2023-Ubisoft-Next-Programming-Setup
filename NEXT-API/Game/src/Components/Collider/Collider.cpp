#include "stdafx.h"
#include "Collider.h"

#include "../src/Scene/Scene.h"



Collider::Collider() : radius(0.0f)
{
}

bool Collider::IsHit(Scene &scene, int a, int b)
{

    Vector3 from = scene.GetTransform(a).position;
    Vector3 to = scene.GetTransform(b).position;

    /*
    if (Vector3::Distance(from, to) > scene.GetCollider(a).radius + scene.GetCollider(b).radius)
    {
        return false;
    }
    else
    { 
        return true;
    }
    */
    return false;
}
