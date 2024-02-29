#include <iostream>
#include "projectile.h"
#include "shooter.h"

#define FRAME_RATE 144

using namespace std;

int main()
{
	cout << "TESawdwadawdawdadawdwadT" << endl;
	// Initialize window
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "JIMGAV'S BEST GAME OF THE YEAR");
	SetTargetFPS(FRAME_RATE);

	// Initialize Shooter
	Shooter shooter;

	Vector2 previousMousePosition = GetMousePosition();
	Vector2 currentMousePosition;

	// Mainloop
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(BLACK);
		DrawFPS(10, 10);

		currentMousePosition = GetMousePosition();
		float deltaTime = GetFrameTime();

		// Calculate mouse velocity
		Vector2 mouseVelocity = {
				(currentMousePosition.x - previousMousePosition.x) / deltaTime,
				(currentMousePosition.y - previousMousePosition.y) / deltaTime};

		// Manage shooter
		shooter.handle_input();
		shooter.draw();

		// Manage projectiles
		for (Projectile &proj : shooter.proj_list)
		{
			proj.move();
			proj.draw();
			if (proj.isBeingDragged)
				proj.vel = mouseVelocity;

			// Activate projectile when leaving shooter
			if (!CheckCollisionCircles(shooter.position, shooter.radius, proj.position, proj.radius))
				proj.active = true;
		}

		// Remove eaten projectiles
		list<Projectile>::iterator it = shooter.proj_list.begin();
		for (auto it = shooter.proj_list.begin(); it != shooter.proj_list.end(); it++)
			if (it->active && CheckCollisionCircles(shooter.position, shooter.radius, it->position, it->radius))
			{
				it = shooter.proj_list.erase(it);
				shooter.radius+=0.5;
			}

		EndDrawing();
		previousMousePosition = currentMousePosition;
	}
	CloseWindow();
}