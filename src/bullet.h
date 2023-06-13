#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "entity.h"

class Bullet : public Entity
{
public:
	Bullet(Texture2D t);
	virtual ~Bullet();

	void Update();

private:
	/* add your private declarations */
};

#endif 