#pragma once

// ToDo: Namespace for characters. Then I can get information by Characters::BoomBot

/// <summary>
/// Default structure for building a character.
/// Holds MovementSpeed, PlayerHealth, MaxActiveBombs, and Sprite.
/// </summary>
struct Character
{

	float MovementSpeed = 1;
	float PlayerHealth = 1;
	float MaxActiveBombs = 1;

	CSimpleSprite* sprite;

	enum CharacterAnims
	{
		ANIM_FORWARDS,
		ANIM_BACKWARDS,
		ANIM_LEFT,
		ANIM_RIGHT,
		ANIM_DEATH,
	};

	virtual void CreateAnimations() = 0;

};


struct BoomBot : Character
{

	float MovementSpeed = 3;
	float PlayerHealth = 3;
	float MaxActiveBombs = 3;
	CSimpleSprite* Sprite;
	//std::string SpriteBMPAddress = ".\\..\\Data\\steambot_03.bmp";

	BoomBot::BoomBot()
	{
		Sprite = App::CreateSprite(".\\..\\Data\\steambot_03.bmp", 5, 1);
	}

	void CreateAnimations() override
	{
		// ToDo: Find new sprite sheet and implement animations
	}

};

struct BoomWizard : Character
{

	float MovementSpeed = 2;
	float PlayerHealth = 2;
	float MaxActiveBombs = 2;
	CSimpleSprite* Sprite;

	BoomWizard()
	{
		Sprite = App::CreateSprite(".\\..\\Data\\Test.bmp", 8, 4);
	}

	void CreateAnimations() override
	{
		float speed = 1.0f / 15.0f;

		sprite->CreateAnimation(ANIM_BACKWARDS, speed, { 0,1,2,3,4,5,6,7 });
		sprite->CreateAnimation(ANIM_LEFT, speed, { 8,9,10,11,12,13,14,15 });
		sprite->CreateAnimation(ANIM_RIGHT, speed, { 16,17,18,19,20,21,22,23 });
		sprite->CreateAnimation(ANIM_FORWARDS, speed, { 24,25,26,27,28,29,30,31 });

	}

};



