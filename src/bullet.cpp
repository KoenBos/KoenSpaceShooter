#include "bullet.h"
#include "raylib.h"
#include "resourcemanager.h"

Bullet::Bullet(Texture2D t) : Entity(t)
{
	//randomize speed
	speed = GetRandomValue(800, 1000);
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{

	//this->y -= speed * GetFrameTime();
	this->x += 5 * sin(GetTime() * 100);

	//move bullets up the with the angle and speed variables
	if (angle == 0)
	{
		this->y -= speed * GetFrameTime();
	}
	if (angle == 1)
	{
		this->y -= speed * GetFrameTime();
		this->x += speed /2 * GetFrameTime();
	}
	if (angle == 2)
	{
		this->y -= speed * GetFrameTime();
		this->x -= speed /2 * GetFrameTime();
	}
}
