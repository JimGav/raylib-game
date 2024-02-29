#include "projectile.h"
#include <iostream>
#include <cmath>

// Constructor
Projectile::Projectile(Vector2 spawn_position, Vector2 target_pos, float radius, float shooter_radius)
{
	position.x = spawn_position.x;
	position.y = spawn_position.y;

	speed_factor = 1;
	this->radius = radius;
	bool isBeingDragged = false;
	color = CLITERAL(Color){(unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), (unsigned char)GetRandomValue(0, 255), 255};
	active = false;

	vel.x = target_pos.x - position.x;
	vel.y = target_pos.y - position.y;
}

// Draw the character
void Projectile::draw()
{
	DrawCircle(position.x, position.y, radius, color);
}

// Move the projectile
void Projectile::move()
{
	position.x += vel.x * speed_factor * GetFrameTime();
	position.y += vel.y * speed_factor * GetFrameTime();

	// Bounce projectile on screen edges

	if (position.x < 0 || position.x > SCREEN_WIDTH)
		vel.x *= -1;
	if (position.y < 0 || position.y > SCREEN_HEIGHT)
		vel.y *= -1;

	// Drag projectile
	if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && CheckCollisionPointCircle(GetMousePosition(), position, radius))
		isBeingDragged = true;
	if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT))
		isBeingDragged = false;
	if (isBeingDragged)
		position = GetMousePosition();
}

// Overload == operator
bool Projectile::operator==(const Projectile &b)
{
	return position.x == b.position.x && position.y == b.position.y && radius == b.radius;
};