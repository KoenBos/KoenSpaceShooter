#include "player.h"
#include "raylib.h"

Player::Player(Texture2D t) : Entity(t)
{
	alive = true;

}

Player::~Player()
{

}

void Player::Update()
{
	if (alive)
	{
		if (IsKeyDown('A'))
		{
			this->x -= 500 * GetFrameTime();
		}
		if (IsKeyDown('D'))
		{
			this->x += 500 * GetFrameTime();
		}
	}
}