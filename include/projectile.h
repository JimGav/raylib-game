#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <raylib.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

class Projectile
{
public:
	Vector2 position;
	Vector2 vel;
	float speed_factor;
	float radius;
	bool isBeingDragged;
	Color color;
	bool active;

	// Constructor
	Projectile(Vector2 spawn_position, Vector2 target_pos, float radius, float shooter_radius);

	// Draw the character
	void draw();

	// Move the projectile
	void move();

	// Overload == operator
	bool operator==(const Projectile &b);
};

#endif