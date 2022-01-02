#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;
	p2List<PhysBody3D*> physBodyCubes;
	PhysBody3D* wall1;
	p2List<Cube*> cubes;
	
	Cube* cube;
	Cube* cube2;
	Cube* cube3;
	Cube* cube4;
	Cube* cube5;
	Cube* cube6;
	Cube* cube7;
	Cube* cube8;
	Cube* cube9;
	Cube* cube10;
	Cube* cube11;
	Cube* cube12;
	Cube* cube13;
	Cube* cube14;
	Cube* cube15;
	Cube* cube16;
	Cube* cube17;
	Cube* cube18;
	Cube* cube19;
	Cube* cube20;
	//map
	Cube ground;
};