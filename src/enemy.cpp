#include "enemy.h"
#include "resourcemanager.h"

Enemy::Enemy(Texture2D t) : Entity(t)
{
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	this->y += 10 * GetFrameTime();
	if (player != nullptr) {
		//follow player
		if (player->x > this->x) {
			this->x += 100 * GetFrameTime();
		}
		else if (player->x < this->x) {
			this->x -= 100 * GetFrameTime();
		}
	}
	
}