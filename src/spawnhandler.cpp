#include "spawnhandler.h"
#include "raylib.h"



Spawnhandler::Spawnhandler(Texture2D t) : Entity(t)
{

}

Spawnhandler::~Spawnhandler()
{

}

void Spawnhandler::Update()
{
	if (IsKeyDown('Q'))
	{
		Spawn();
	}
}

void Spawnhandler::Spawn()
{
	Enemy* enemy = new Enemy(rs->GetTexture(ASSETS_PATH"enemy.png"));
	enemys.push_back(enemy);
	enemy->x = x + GetRandomValue(-270, 220);
	enemy->y = 0;
}