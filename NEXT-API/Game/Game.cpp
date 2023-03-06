#include "stdafx.h"
#include "./src/App/app.h"
#include <math.h>  
#include "src/Scene/Scene.h"

// Tests
#include "./src//Math/Vector3/Vector3Test.cpp"
#include "./src/Objects/GameObjectTest.cpp"


Scene scene; 
GameManager gameManager;

//------------------------------------------------------------------------
// Called before first update. Do any initial setup here.
//------------------------------------------------------------------------
void Init()
{

#ifdef DEBUG
	std::string resultString = ("Vector3Tests:  \n"); // You must change this print before running to get an update printed to the immediate window. Adding white space after colon works perfectly.
	OutputDebugStringA(resultString.c_str());
	Vector3Test::RunTests();

	std::string resultString2 = ("GameObjectTests:\n"); // You must change this print to get an update printed to the immediate window. Adding white space after colon works perfectly.
	OutputDebugStringA(resultString2.c_str());
	GameObjectTest::RunTests();
#endif // DEBUG



	scene.Init();
	gameManager.Init();
	// ui.Init(scene);

			

}

//------------------------------------------------------------------------
// Update your simulation here. deltaTime is the elapsed time since the last update in ms.
// This will be called at no greater frequency than the value of APP_MAX_FRAME_RATE
//------------------------------------------------------------------------
void Update(float deltaTime)
{
	
	scene.Update(deltaTime);
	//madeCharacter->SetDeltaTime(deltaTime);

}


// NOTE: Called continously like Update()
//------------------------------------------------------------------------
// Add your display calls here (DrawLine,Print, DrawSprite.) 
// See App.h 
//------------------------------------------------------------------------
void Render()
{

	scene.Render();
	gameManager.DrawMapGrid(14, 11); // These numbers are a good size

}


//------------------------------------------------------------------------
// Add your shutdown code here. Called when the APP_QUIT_KEY is pressed.
// Just before the app exits.
//------------------------------------------------------------------------
void Shutdown()
{

}
