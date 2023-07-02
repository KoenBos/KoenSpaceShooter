#include "player.h"
#include "raylib.h"


Player::Player(Texture2D t) : Entity(t)
{
	alive = true;
	score = 0;
	shootDelay = 0.5f;
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
		if (IsKeyDown('W') && y >= 500)
		{
			y -= 500 * GetFrameTime();
		}
		if (IsKeyDown('S') && y <= 800)
		{
			y += 500 * GetFrameTime();
		}

		if (IsKeyDown(KEY_SPACE) && GetTime() > delay + shootDelay)
		{
			Shoot();
			delay = GetTime();
		}

		if (x > 600)
		{
			x = -100;
		}
		if (x < -100)
		{
			x = 600;
		}
	}

}

//shoot bullet
void Player::Shoot()
{ 
	Bullet* bullet = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));
	bullet->x = x + 35;
	bullet->y = y;
	bullets.push_back(bullet);
}