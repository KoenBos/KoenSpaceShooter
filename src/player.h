#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player: public Entity
{
public:
	Player(Texture2D t);
	virtual ~Player();

	void Update();
	bool alive;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

private:
	/* add your private declarations */
};

#endif /* PLAYER_H */
