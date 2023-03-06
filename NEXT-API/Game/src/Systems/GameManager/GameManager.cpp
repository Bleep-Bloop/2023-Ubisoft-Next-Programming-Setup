#include "stdafx.h"
#include "GameManager.h"


void GameManager::DrawMapGrid(float numOfHorizontalBoxes, float numOfVerticalBoxes)
{

	// ToDo: return a vector of transform cordinates we can create boxes on
	// add to std::vector<x,y> make struct for it.

	float numberOfHorionztalBoxes = numOfHorizontalBoxes; // 14; is nice
	float horizontalSpacing = APP_VIRTUAL_WIDTH / numberOfHorionztalBoxes;

	float startX1 = 0;	float startY1 = 0;
	float endX1 = 0;	float endY1 = 0;

	for (int i = 0; i < numberOfHorionztalBoxes; i++)
	{
		startX1 += horizontalSpacing;
		startY1 = 0;
		endX1 += horizontalSpacing;
		endY1 = APP_VIRTUAL_HEIGHT;

		App::DrawLine(startX1, startY1, endX1, endY1);
	}

	float startX2 = 0;	float startY2 = 0;
	float endX2 = 0;	float endY2 = 0;

	float numberOfVerticalBoxes = numOfVerticalBoxes;
	float verticalSpacing = APP_VIRTUAL_HEIGHT / numberOfVerticalBoxes;

	for (int j = 0; j < numberOfVerticalBoxes; j++)
	{
		startX2 = 0;
		startY2 += verticalSpacing;
		endX2 = APP_VIRTUAL_WIDTH;
		endY2 += verticalSpacing;

		App::DrawLine(startX2, startY2, endX2, endY2);
	}

}

void GameManager::CreateLevel()
{

}

void GameManager::Init()
{

	// ToDo: Create Level here
	CreateLevel(); 

}
