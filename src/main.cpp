#include "raylib.h"
#include "player.h"

constexpr auto SCREEN_WIDTH  = 1920;
constexpr auto SCREEN_HEIGHT = 1080;
//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------

int main()
{
	InitWindow(GetScreenWidth() , GetScreenHeight(), "Window title");
    SetTargetFPS(60);
	void ToggleFullscreen(void);

    Texture2D texture = LoadTexture(ASSETS_PATH"test.png"); // to resourcemanager
    Player* player = new Player(texture); // get texture from resourcemanager

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(RAYWHITE);

		player->show();
		player->Update();

		//const char* text = "Player";
		//const Vector2 text_size = MeasureTextEx(GetFontDefault(), text, 20, 1);
		//DrawText(text, SCREEN_WIDTH / 2 - text_size.x / 2, SCREEN_HEIGHT / 2 - texture.height / 2 + texture.height + text_size.y + 10, 20, BLACK);

		EndDrawing();
		if (IsKeyPressed('P')) {
			ToggleFullscreen();
		}
	}
	UnloadTexture(texture);

	CloseWindow();
	return 0;
}
