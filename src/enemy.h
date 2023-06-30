#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "entity.h"
#include "player.h"

class Enemy : public Entity
{
public:
	Enemy(Texture2D t);
	virtual ~Enemy();

	void Update();
	Texture2D t;
	Player* player;
	int health = 100;


		

private:
	/* add your private declarations */
};

#endif 
