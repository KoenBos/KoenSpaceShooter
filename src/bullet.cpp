#include "bullet.h"
#include "raylib.h"
#include "resourcemanager.h"

Bullet::Bullet(Texture2D t) : Entity(t)
{

}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	this->y -= 500 * GetFrameTime();
}