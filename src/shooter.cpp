#include "shooter.h"

// Constructor
Shooter::Shooter()
{
	position.x = SCREEN_WIDTH / 2;
	position.y = SCREEN_HEIGHT / 2;

	vel.x = 2;
	vel.y = 2;

	radius = 20;
}

// Draw the character
void Shooter::draw()
{
	DrawCircle(position.x, position.y, radius, RAYWHITE);
}
// Move the character
void Shooter::handle_input()
{
	// Update position
	if (IsKeyDown(KEY_D))
		position.x += vel.x;
	if (IsKeyDown(KEY_A))
		position.x -= vel.x;
	if (IsKeyDown(KEY_W))
		position.y -= vel.y;
	if (IsKeyDown(KEY_S))
		position.y += vel.y;

	// Shoot
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		Projectile proj(position, {(float)GetMouseX(), (float)GetMouseY()}, 5, radius);
		proj_list.push_back(proj);

		if (radius > 1)
			radius-=0.5;
	}
}
