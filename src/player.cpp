#include "player.h"
#include "raylib.h"

Player::Player(Texture2D t) : Entity(t)
{
	alive = true;
	SCREEN_WIDTH = GetScreenWidth();
	SCREEN_HEIGHT = GetScreenHeight();
	this->x = SCREEN_WIDTH / 2 - t.width / 2;
	this->y = SCREEN_HEIGHT / 10 * 9 - t.height / 2;
}

Player::~Player()
{

}

void Player::Update()
{
	if (alive == true)
	{
		if (IsKeyDown('A'))
		{
			this->x -= 500 * GetFrameTime();
		}
		if (IsKeyDown('D'))
		{
			this->x += 500 * GetFrameTime();
		}
		if (IsKeyPressed('W'))
		{
			this->x += 500 * GetFrameTime();
		}
	}
}