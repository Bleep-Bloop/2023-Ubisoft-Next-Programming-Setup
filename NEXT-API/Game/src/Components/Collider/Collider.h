#pragma once

class Scene;
struct Transform;

// ToDo: Rethink implementation of Collider. 
// ToDo: When calling in the Update() function have a check on each collider and then call
// the respective function, don't just list them both.
struct Collider
{
	float radius;

	Collider();

	bool isTrigger;

	// ToDo: Clean up. To many parameters. Could pass reference and get everything from there.
	static bool IsHit(Scene &scene, int ID, Transform aTransform, Collider aCollider, int otherID, Transform bTransform, Collider bCollider);

	static bool IsOverlapping(Scene& scene, int ID, Transform aTransform, Collider aCollider, int otherID, Transform bTransform, Collider bCollider);

};

