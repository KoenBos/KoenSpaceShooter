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
	this->y -= speed * GetFrameTime();
	this->x += 5 * sin(GetTime() * 100);
}