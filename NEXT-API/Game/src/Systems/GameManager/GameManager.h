#pragma once
// can I put GOACTOR include here?
// I think I need to hold them all.

#include "../src/Objects/Actor/GOActor.h"


/// <summary>
/// GameManager handles the runtime aspects of the game. 
/// Players, score, level creation, etc/
/// </summary>
class GameManager
{
public:

	/// <summary>
	/// Draw a grid across the screen.
	/// </summary>
	/// <param name="horizontalBoxNumber">Number of boxes along width of window</param>
	/// <param name="verticalBoxNumber">Number of boxes along height of window</param>
	void DrawMapGrid(float horizontalBoxNumber, float verticalBoxNumber);

	void CreateLevel();

	//GOActor* player1;
	//GOActor* player2;

	// ToDo: Crate Level and set up characters. 
	void Init();
	


};

