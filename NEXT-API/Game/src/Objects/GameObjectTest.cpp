#include "stdafx.h"
#include <Windows.h>
#include "./GameObject.h"
#include "../Math/Vector3/Vector3.h"


class GameObjectTest
{

public:
    static void RunTests()
    {

        Scene* testScene = new Scene();
        CSimpleSprite* testSprite = App::CreateSprite(".\\..\\Data\\steambot_03.bmp", 5, 1);
        Transform testTransform;
        testTransform.position = Vector3(400, 400, 400);
        testTransform.rotation = Vector3::Zero;
        testTransform.scale = Vector3(5,1,1);
        
        CreateGameObjectTest(*testScene, *testSprite, testTransform);
       
    }

    // Render must be called from Game.cpp->Render()
    static void RenderTest(GameObject* gameObject)
    {
        gameObject->Render();
    }

private:

    static void CreateGameObjectTest(Scene& scene, CSimpleSprite &sprite, Transform transform)
    {
        GameObject* object = new GameObject(scene, sprite, transform);
        RenderTest(object);
    }

};