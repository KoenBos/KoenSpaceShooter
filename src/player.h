#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "bullet.h"
#include "resourcemanager.h"
#include <vector>

class Player: public Entity
{
public:
	Player(Texture2D t);
	virtual ~Player();

	void Update();
	void Shoot();
	void Upgrade();
	bool alive;
	int score;
	int money;
	int cost = 15;
	bool multiShot = false;
	int level = 1;
	float shootDelay;
	float delay;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	ResourceManager* rs = ResourceManager::Instance();

	std::vector<Bullet*> bullets;


private:
	/* add your private declarations */
};

#endif /* PLAYER_H */
