#ifndef SPAWNHANDLER_H
#define SPAWNHANDLER_H

#include "entity.h"
#include "enemy.h"
#include "resourcemanager.h"
#include <vector>

class Spawnhandler : public Entity
{
public:
	Spawnhandler(Texture2D t);
	virtual ~Spawnhandler();

	void Update();
	void Spawn();
	ResourceManager* rs = ResourceManager::Instance();

	std::vector<Enemy*> enemys;


private:
	/* add your private declarations */
};

#endif /* PLAYER_H */
