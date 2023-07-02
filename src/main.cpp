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

	ResourceManager* rs = ResourceManager::Instance();

	
    Player* player = new Player(rs->GetTexture(ASSETS_PATH"test.png")); // get texture from resourcemanager

	Spawnhandler* spawnhandler = new Spawnhandler(rs->GetTexture(ASSETS_PATH"test.png"));

	spawnhandler->x = SCREEN_WIDTH / 2;
	spawnhandler->y = SCREEN_HEIGHT / 10;

	player->x = SCREEN_WIDTH / 2;
	player->y = SCREEN_HEIGHT / 10 * 8;


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);

		if (player->alive)
		{
			player->show();
			player->Update();
			DrawText(FormatText("Score: %i", player->score), 10, 10, 30, WHITE);
		}
		else
		{
			DrawText(FormatText("Score: %i", player->score), SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 +70, 40, GREEN);
			DrawText("Game Over", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2, 50, RED);
		}


		spawnhandler->Update();

		//bullet render update and collision
		if (!player->bullets.empty()) {
			for (int i = player->bullets.size() -1; i >= 0; i--)
			{
				player->bullets[i]->show();
				player->bullets[i]->Update();
				for (int j = spawnhandler->enemys.size() -1 ; j >= 0; j--)
				{
					if (CheckCollisionCircles(Vector2(spawnhandler->enemys[j]->x, spawnhandler->enemys[j]->y), 20.0f, Vector2(player->bullets[i]->x, player->bullets[i]->y), 20.0f))
					{
						delete player->bullets[i];
						delete spawnhandler->enemys[j];
						spawnhandler->enemys.erase(spawnhandler->enemys.begin() + j);
						player->score++;
					}
				}
			}
		}
		for (int x = spawnhandler->enemys.size() - 1; x >= 0; x--)
		{
			spawnhandler->enemys[x]->player = player;
			spawnhandler->enemys[x]->show();
			spawnhandler->enemys[x]->Update();
			if (CheckCollisionCircles(Vector2(spawnhandler->enemys[x]->x, spawnhandler->enemys[x]->y), 20.0f, Vector2(player->x, player->y), 20.0f))
			{
				player->alive = false;
			}
		}
		



		EndDrawing();
	}
	//unload all textures
	//ResourceManager::Cleanup();

	CloseWindow();
	return 0;
}
