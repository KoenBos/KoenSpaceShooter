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
			x -= 500 * GetFrameTime();
		}
		if (IsKeyDown('D'))
		{
			x += 500 * GetFrameTime();
		}
		//if key space is pressed, shoot bullet
		if (IsKeyPressed(KEY_SPACE))
		{
			Shoot();
		}
	}
}

//shoot bullet
void Player::Shoot()
{ 
	Bullet* bullet = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));
	bullet->x = x;
	bullet->y = y;
	bullets.push_back(bullet);
}