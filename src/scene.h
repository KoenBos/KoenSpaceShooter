#ifndef SCENE_H
#define SCENE_H

#include "raylib.h"

class Scene
{
public:
	Scene();
	virtual ~Scene();

	void show();
	
	//if(textures.contains(filename))


	float x;
	float y;

private:
	/* add your private declarations */
};

#endif /* ENTITY_H */
