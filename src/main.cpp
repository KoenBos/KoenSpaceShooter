#include "raylib.h"
#include "player.h"
#include "bullet.h"
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

	Bullet* bullet = new Bullet(rs->GetTexture(ASSETS_PATH"bullet.png"));

	player->x = SCREEN_WIDTH / 2;
	player->y = SCREEN_HEIGHT / 10 * 9;

	bullet->x = SCREEN_WIDTH / 2;
	bullet->y = SCREEN_HEIGHT / 2;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		player->show();
		bullet->show();
		bullet->Update();
		player->Update();


		EndDrawing();
	}
	//unload all textures
	//ResourceManager::Cleanup();

	CloseWindow();
	return 0;
}
