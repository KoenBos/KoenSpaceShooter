#include "raylib.h"
#include "player.h"
#include "resourcemanager.h"

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


	player->x = SCREEN_WIDTH / 2;
	player->y = SCREEN_HEIGHT / 10 * 9;


	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		player->show();
		//bullet->show();
		//bullet->Update();
		//player->bullets[0]->show();
		player->Update();
		for (int i = 0; i < player->bullets.size(); i++)
		{
			player->bullets[i]->show();
			player->bullets[i]->Update();
		}


		EndDrawing();
	}
	//unload all textures
	//ResourceManager::Cleanup();

	CloseWindow();
	return 0;
}
