#include "stdafx.h"
#include "Collider.h"
#include "../src/Scene/Scene.h"


Collider::Collider() : radius(0.0f), isTrigger(false)
{
}

bool Collider::IsHit(Scene &scene, int ID, Transform aTransform, Collider aCollider, int otherID, Transform bTransform, Collider bCollider)
{

    if (ID != otherID)
    {

        Vector3 from = aTransform.position;
        Vector3 to = bTransform.position;

        if (Vector3::Distance(from, to) < aCollider.radius + bCollider.radius)
        {
            return true;
        }
        else
        {
            return false;
        }
   
    }
    else
    {
        // If the item is checking against itself flag false.
        return false;
    }

}

// ToDo: Implementation
bool Collider::IsOverlapping(Scene& scene, int ID, Transform aTransform, Collider aCollider, int otherID, Transform bTransform, Collider bCollider)
{
    return false;
}
