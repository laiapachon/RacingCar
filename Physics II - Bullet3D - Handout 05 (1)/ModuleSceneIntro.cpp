#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"
#include "Globals.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	
	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));


	
	//MAP
	//circuito
	cube = new Cube(2, 2, 80);
	cube->SetPos(15, 0, 70);
	cube->color.Set(0, 153, 0);
	cubes.add(cube);
	physBodyCubes.add(App->physics->AddBody(*cube, 0));

	cube2 = new Cube(2, 2, 80);
	cube2->SetPos(-15, 0, 70);
	cube2->color.Set(0, 153, 0);
	cubes.add(cube2);
	physBodyCubes.add(App->physics->AddBody(*cube2, 0));

	cube3 = new Cube(2, 2, 40);
	cube3->SetPos(-15, 0, 140);
	cube3->color.Set(0, 153, 0);
	cubes.add(cube3);
	physBodyCubes.add(App->physics->AddBody(*cube3, 0));

	cube4 = new Cube(2, 2, 40);
	cube4->SetPos(15, 0, 140);
	cube4->color.Set(0, 153, 0);
	cubes.add(cube4);
	physBodyCubes.add(App->physics->AddBody(*cube4, 0));

	cube5 = new Cube(2, 2, 20);
	cube5->SetPos(-15, 0, 180);
	cube5->color.Set(0, 153, 0);
	cubes.add(cube5);
	physBodyCubes.add(App->physics->AddBody(*cube5, 0));

	cube6 = new Cube(2, 2, 20);
	cube6->SetPos(15, 0, 180);
	cube6->color.Set(0, 153, 0);
	cubes.add(cube6);
	physBodyCubes.add(App->physics->AddBody(*cube6, 0));

	cube7 = new Cube(2, 2, 20);
	cube7->SetPos(15, 0, 210);
	cube7->color.Set(0, 153, 0);
	cubes.add(cube7);
	physBodyCubes.add(App->physics->AddBody(*cube7, 0));

	cube8 = new Cube(2, 2, 20);
	cube8->SetPos(-15, 0, 210);
	cube8->color.Set(0, 153, 0);
	cubes.add(cube8);
	physBodyCubes.add(App->physics->AddBody(*cube8, 0));

	cube9 = new Cube(2, 2, 20);
	cube9->SetPos(-15, 0, 240);
	cube9->color.Set(0, 153, 0);
	cubes.add(cube9);
	physBodyCubes.add(App->physics->AddBody(*cube9, 0));

	cube10 = new Cube(2, 2, 20);
	cube10->SetPos(15, 0, 240);
	cube10->color.Set(0, 153, 0);
	cubes.add(cube10);
	physBodyCubes.add(App->physics->AddBody(*cube10, 0));

	cube11 = new Cube(2, 2, 20);
	cube11->SetPos(15, 0, 280);
	cube11->color.Set(0, 153, 0);
	cubes.add(cube11);
	physBodyCubes.add(App->physics->AddBody(*cube11, 0));

	cube12 = new Cube(2, 2, 20);
	cube12->SetPos(-15, 0, 280);
	cube12->color.Set(0, 153, 0);
	cubes.add(cube12);
	physBodyCubes.add(App->physics->AddBody(*cube12, 0));

	cube13 = new Cube(2, 2, 20);
	cube13->SetPos(-15, 0, 310);
	cube13->color.Set(0, 153, 0);
	cubes.add(cube13);
	physBodyCubes.add(App->physics->AddBody(*cube13, 0));

	cube14 = new Cube(2, 2, 20);
	cube14->SetPos(15, 0, 310);
	cube14->color.Set(0, 153, 0);
	cubes.add(cube14);
	physBodyCubes.add(App->physics->AddBody(*cube14, 0));

	cube15 = new Cube(2, 2, 10);
	cube15->SetPos(-15, 0, 340);
	cube15->color.Set(0, 153, 0);
	cubes.add(cube15);
	physBodyCubes.add(App->physics->AddBody(*cube15, 0));

	cube16 = new Cube(2, 2, 20);
	cube16->SetPos(15, 0, 340);
	cube16->color.Set(0, 153, 0);
	cubes.add(cube16);
	physBodyCubes.add(App->physics->AddBody(*cube16, 0));

	cube17 = new Cube(2, 2, 10);
	cube17->SetPos(14, 0, 360);
	cube17->SetRotation(170.0f, { 0,0.5,0 });
	cube17->color.Set(0, 153, 0);
	cubes.add(cube17);
	physBodyCubes.add(App->physics->AddBody(*cube17, 0));

	cube18 = new Cube(2, 2, 10);
	cube18->SetPos(-16, 0, 360);
	cube18->SetRotation(170.0f, { 0,0.5,0 });
	cube18->color.Set(0, 153, 0);
	cubes.add(cube18);
	physBodyCubes.add(App->physics->AddBody(*cube18, 0));

	cube19 = new Cube(2, 2, 10);
	cube19->SetPos(12, 0, 380);
	cube19->SetRotation(170.0f, { 0,0.5,0 });
	cube19->color.Set(0, 153, 0);
	cubes.add(cube19);
	physBodyCubes.add(App->physics->AddBody(*cube19, 0));

	cube20 = new Cube(2, 2, 10);
	cube20->SetPos(-18, 0, 380);
	cube20->SetRotation(170.0f, { 0,0.5,0 });
	cube20->color.Set(0, 153, 0);
	cubes.add(cube20);
	physBodyCubes.add(App->physics->AddBody(*cube20, 0));
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	/*Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();*/
	cube->Render();
	cube2->Render();
	cube3->Render();
	cube4->Render();
	cube5->Render();
	cube6->Render();
	cube7->Render();
	cube8->Render();
	cube9->Render();
	cube10->Render();
	cube11->Render();
	cube12->Render();
	cube13->Render();
	cube14->Render();
	cube15->Render();
	cube16->Render();
	cube17->Render();
	cube18->Render();
	cube19->Render();
	cube20->Render();
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

