// entity.h

#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class Entity
{
public:
	Entity(Texture2D t);
	virtual ~Entity();

	void show();

	float x;
	float y;

private:
	/* add your private declarations */
	Texture2D texture;
};

#endif /* ENTITY_H */
