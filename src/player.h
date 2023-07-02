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
	bool alive;
	int score;
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
