#include "enemy.h"
#include "resourcemanager.h"

Enemy::Enemy(Texture2D t) : Entity(t)
{
	speed = GetRandomValue(100, 150);
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	if (player->alive)
	{
		if (y <= 400) {
			this->x += 5 * sin(GetTime() * 8);
			this->y += speed * GetFrameTime();
		}
		else
		{
			if (player->x + 35 > x)
			{
				x += speed * GetFrameTime();
			}
			if (player->x + 35 < x)
			{
				x -= speed * GetFrameTime();
			}
			if (player->y + 35 > y)
			{
				y += speed * GetFrameTime();
			}
			if (player->y + 35 < y)
			{
				y -= speed * GetFrameTime();
			}
		}
	}
	else
	{
		this->x += 5 * sin(GetTime() * 8);
		this->y -= speed * GetFrameTime();
	}
	

}