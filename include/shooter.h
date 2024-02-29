#ifndef SHOOTER_H
#define SHOOTER_H

#include <list>
#include "raylib.h"
#include "projectile.h"


class Shooter
{
public:
	Vector2 position;
	Vector2 vel;
	std::list<Projectile> proj_list;
	float radius;

	// Constructor
	Shooter();

	// Draw the character
	void draw();

	// Move the character
	void handle_input();
};

#endif