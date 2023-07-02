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
			DrawText(FormatText("Score: %i", player->score), 10, 10, 20, WHITE);
			DrawText(FormatText("Wave: %i", spawnhandler->wave), SCREEN_WIDTH / 2 - 50, 10, 30, RED);
			DrawText(FormatText("$: %i", player->money), SCREEN_WIDTH -100, 10, 20, GOLD);
			DrawText("E = Upgrade", SCREEN_WIDTH - 150, SCREEN_HEIGHT - 50, 20, WHITE);
			DrawText(FormatText("Cost: %i", player->level * 15), SCREEN_WIDTH - 120, SCREEN_HEIGHT - 25, 20, BLUE);
		}
		else
		{
			DrawText(FormatText("Score: %i", player->score), SCREEN_WIDTH / 2 - 80, SCREEN_HEIGHT / 2 - 50, 30, GREEN);
			DrawText("Game Over", SCREEN_WIDTH / 2 - 140, SCREEN_HEIGHT / 2 -100, 50, RED);
			DrawText(FormatText("Wave: %i", spawnhandler->wave), SCREEN_WIDTH / 2 - 70, SCREEN_HEIGHT / 2 - 20, 30, BLUE);
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
						spawnhandler->enemys.erase(spawnhandler->enemys.begin() + j);
						player->bullets.erase(player->bullets.begin() + i);
						player->score++;
						player->money++;
						break;

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
	CloseWindow();
	return 0;
}
