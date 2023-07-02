#include "player.h"
#include "raylib.h"


Player::Player(Texture2D t) : Entity(t)
{
	alive = true;
	score = 0;
	money = 0;
	shootDelay = 0.3f;
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
		if (IsKeyPressed('E'))
		{
			Upgrade();
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
	if (multiShot) {
		//shoot 3 bullets at once with a spread of 10 degrees between each bullet
		Bullet* bullet = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));
		bullet->x = x + 35;
		bullet->y = y;
		bullets.push_back(bullet);

		Bullet* bullet2 = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));
		bullet2->x = x + 35;
		bullet2->y = y;
		bullet2->angle = 1;
		bullets.push_back(bullet2);
		
		Bullet* bullet3 = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));
		bullet3->x = x + 35;
		bullet3->y = y;
		bullet3->angle = 2;
		bullets.push_back(bullet3);
	}
	else
	{
		Bullet* bullet = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));
		bullet->x = x + 35;
		bullet->y = y;
		bullets.push_back(bullet);
	}
}

void Player::Upgrade()
{

	if (money >= level * cost)
	{
		if (shootDelay >= 0.15f) {
			shootDelay -= 0.05f;
			money -= level * cost;
			level++;
		}
		else if (multiShot == false)
		{
			multiShot = true;
			money -= level * cost;
			level++;
		}
	}
}