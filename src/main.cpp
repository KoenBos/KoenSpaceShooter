#include "raylib.h"
#include "player.h"
#include "resourcemanager.h"
#include "spawnhandler.h"

constexpr auto SCREEN_WIDTH  = 600;
constexpr auto SCREEN_HEIGHT = 900;
//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------

int main()
{
	InitWindow(SCREEN_WIDTH , SCREEN_HEIGHT, "Window title");
    SetTargetFPS(60);
	void ToggleFullscreen(void);
	Vector3 vec = { 1.0f, 2.0f, 3.0f };
	float length_squared = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

	ResourceManager* rs = ResourceManager::Instance();

	
    Player* player = new Player(rs->GetTexture(ASSETS_PATH"test.png")); // get texture from resourcemanager

	Spawnhandler* spawnhandler = new Spawnhandler(rs->GetTexture(ASSETS_PATH"test.png"));

	spawnhandler->x = SCREEN_WIDTH / 2;
	spawnhandler->y = SCREEN_HEIGHT / 10;

	player->x = SCREEN_WIDTH / 2;
	player->y = SCREEN_HEIGHT / 10 * 9;


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		player->show();
		player->Update();

		spawnhandler->Update();

		//bullet render update and collision
		for (int i = player->bullets.size() - 1; i >= 0; i--)
		{
			player->bullets[i]->show();
			player->bullets[i]->Update();
			for (int j = spawnhandler->enemys.size() - 1; j >= 0; j--)
			{
				if (CheckCollisionCircles(Vector2(spawnhandler->enemys[j]->x, spawnhandler->enemys[j]->y), 20, Vector2(player->bullets[i]->x, player->bullets[i]->y), 20))
				{
					std::cout << "Enemy Hit!" << std::endl;
					delete player->bullets[i];
					player->bullets.erase(player->bullets.begin() + i);
					delete spawnhandler->enemys[j];
					spawnhandler->enemys.erase(spawnhandler->enemys.begin() + j);
				}
			}
		}
		for (int i = spawnhandler->enemys.size() - 1; i >= 0; i--)
		{
			spawnhandler->enemys[i]->player = player;
			spawnhandler->enemys[i]->show();
			spawnhandler->enemys[i]->Update();
		}
		



		EndDrawing();
	}
	//unload all textures
	//ResourceManager::Cleanup();

	CloseWindow();
	return 0;
}
