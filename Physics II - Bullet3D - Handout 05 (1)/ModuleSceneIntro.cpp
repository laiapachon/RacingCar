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
	cube->color=Oxid;
	cubes.add(cube);
	physBodyCubes.add(App->physics->AddBody(*cube, 0));

	cube2 = new Cube(2, 2, 80);
	cube2->SetPos(-15, 0, 70);
	cube2->color = Oxid;
	cubes.add(cube2);
	physBodyCubes.add(App->physics->AddBody(*cube2, 0));

	cube3 = new Cube(2, 2, 40);
	cube3->SetPos(-15, 0, 140);
	cube3->color = Oxid;
	cubes.add(cube3);
	physBodyCubes.add(App->physics->AddBody(*cube3, 0));

	cube4 = new Cube(2, 2, 40);
	cube4->SetPos(15, 0, 140);
	cube4->color = Oxid;
	cubes.add(cube4);
	physBodyCubes.add(App->physics->AddBody(*cube4, 0));

	cube5 = new Cube(2, 2, 20);
	cube5->SetPos(-15, 0, 180);
	cube5->color = Oxid;
	cubes.add(cube5);
	physBodyCubes.add(App->physics->AddBody(*cube5, 0));

	cube6 = new Cube(2, 2, 20);
	cube6->SetPos(15, 0, 180);
	cube6->color = Oxid;
	cubes.add(cube6);
	physBodyCubes.add(App->physics->AddBody(*cube6, 0));

	cube7 = new Cube(2, 2, 20);
	cube7->SetPos(15, 0, 210);
	cube7->color = Oxid;
	cubes.add(cube7);
	physBodyCubes.add(App->physics->AddBody(*cube7, 0));

	cube8 = new Cube(2, 2, 20);
	cube8->SetPos(-15, 0, 210);
	cube8->color = Oxid;
	cubes.add(cube8);
	physBodyCubes.add(App->physics->AddBody(*cube8, 0));

	cube9 = new Cube(2, 2, 20);
	cube9->SetPos(-15, 0, 240);
	cube9->color = Oxid;
	cubes.add(cube9);
	physBodyCubes.add(App->physics->AddBody(*cube9, 0));

	cube10 = new Cube(2, 2, 20);
	cube10->SetPos(15, 0, 240);
	cube10->color = Oxid;
	cubes.add(cube10);
	physBodyCubes.add(App->physics->AddBody(*cube10, 0));

	cube11 = new Cube(2, 2, 20);
	cube11->SetPos(15, 0, 280);
	cube11->color = Oxid;
	cubes.add(cube11);
	physBodyCubes.add(App->physics->AddBody(*cube11, 0));

	cube12 = new Cube(2, 2, 20);
	cube12->SetPos(-15, 0, 280);
	cube12->color = Oxid;
	cubes.add(cube12);
	physBodyCubes.add(App->physics->AddBody(*cube12, 0));

	cube13 = new Cube(2, 2, 20);
	cube13->SetPos(-15, 0, 310);
	cube13->color = Oxid;
	cubes.add(cube13);
	physBodyCubes.add(App->physics->AddBody(*cube13, 0));

	cube14 = new Cube(2, 2, 20);
	cube14->SetPos(15, 0, 310);
	cube14->color = Oxid;
	cubes.add(cube14);
	physBodyCubes.add(App->physics->AddBody(*cube14, 0));

	cube15 = new Cube(2, 2, 10);
	cube15->SetPos(-15, 0, 340);
	cube15->color = Oxid;
	cubes.add(cube15);
	physBodyCubes.add(App->physics->AddBody(*cube15, 0));

	cube16 = new Cube(2, 2, 20);
	cube16->SetPos(15, 0, 340);
	cube16->color = Oxid;
	cubes.add(cube16);
	physBodyCubes.add(App->physics->AddBody(*cube16, 0));

	cube17 = new Cube(2, 2, 10);
	cube17->SetPos(14, 0, 360);
	cube17->SetRotation(170.0f, { 0,0.5,0 });
	cube17->color = Oxid;
	cubes.add(cube17);
	physBodyCubes.add(App->physics->AddBody(*cube17, 0));

	cube18 = new Cube(2, 2, 10);
	cube18->SetPos(-16, 0, 360);
	cube18->SetRotation(170.0f, { 0,0.5,0 });
	cube18->color = Oxid;
	cubes.add(cube18);
	physBodyCubes.add(App->physics->AddBody(*cube18, 0));

	cube19 = new Cube(2, 2, 10);
	cube19->SetPos(12, 0, 380);
	cube19->SetRotation(170.0f, { 0,0.5,0 });
	cube19->color = Oxid;
	cubes.add(cube19);
	physBodyCubes.add(App->physics->AddBody(*cube19, 0));

	cube20 = new Cube(2, 2, 10);
	cube20->SetPos(-18, 0, 380);
	cube20->SetRotation(170.0f, { 0,0.5,0 });
	cube20->color = Oxid;
	cubes.add(cube20);
	physBodyCubes.add(App->physics->AddBody(*cube20, 0));

	cube21 = new Cube(2, 2, 10);
	cube21->SetPos(6, 0, 400);
	cube21->SetRotation(150.0f, { 0,0.5,0 });
	cube21->color = Oxid;
	cubes.add(cube21);
	physBodyCubes.add(App->physics->AddBody(*cube21, 0));

	cube22 = new Cube(2, 2, 10);
	cube22->SetPos(-24, 0, 400);
	cube22->SetRotation(150.0f, { 0,0.5,0 });
	cube22->color = Oxid;
	cubes.add(cube22);
	physBodyCubes.add(App->physics->AddBody(*cube22, 0));

	cube23 = new Cube(2, 2, 10);
	cube23->SetPos(-4, 0, 420);
	cube23->SetRotation(150.0f, { 0,0.5,0 });
	cube23->color = Oxid;
	cubes.add(cube23);
	physBodyCubes.add(App->physics->AddBody(*cube23, 0));

	cube24 = new Cube(20, 1, 40);
	cube24->SetPos(-20, 0, 420);
	cube24->SetRotation(140.0f, { 0,0.5,0 });
	cube24->color = Oxid;
	cubes.add(cube24);
	physBodyCubes.add(App->physics->AddBody(*cube24, 0));

	cube25 = new Cube(20, 1, 28);
	cube25->SetPos(-40, 0, 444);
	cube25->SetRotation(140.0f, { 0,0.5,0 });
	//cube25->SetRotation(80.0f, { 1,0,0 });
	cube25->color = Oxid;
	cubes.add(cube25);
	physBodyCubes.add(App->physics->AddBody(*cube25, 0));

	cube26 = new Cube(20, 1, 20);
	cube26->SetPos(-48, 2, 460);
	cube26->SetRotation(160.0f, { 0.5,0,0 });
	//cube26->SetRotation(160.0f, { 0,0,1 });
	cube26->color = Oxid;
	cubes.add(cube26);
	physBodyCubes.add(App->physics->AddBody(*cube26, 0));

	cube27 = new Cube(20, 1, 20);
	cube27->SetPos(-48, 8, 478);
	cube27->SetRotation(160.0f, { 0.5,0,0 });
	//cube26->SetRotation(160.0f, { 0,0,1 });
	cube27->color = Oxid;
	cubes.add(cube27);
	physBodyCubes.add(App->physics->AddBody(*cube27, 0));

	cube28 = new Cube(20, 1, 20);
	cube28->SetPos(-48, 12, 498);
	cube28->color = Oxid;
	cubes.add(cube28);
	physBodyCubes.add(App->physics->AddBody(*cube28, 0));

	cube29 = new Cube(20, 1, 20);
	cube29->SetPos(-48, 12, 518);
	cube29->color = Oxid;
	cubes.add(cube29);
	physBodyCubes.add(App->physics->AddBody(*cube29, 0));


	cube30 = new Cube(20, 1, 20);
	cube30->SetPos(-48, 12, 538);
	cube30->color = Oxid;
	cubes.add(cube30);
	physBodyCubes.add(App->physics->AddBody(*cube30, 0));

	cube31 = new Cube(20, 1, 20);
	cube31->SetPos(-48, 12, 558);
	cube31->color = Oxid;
	cubes.add(cube31);
	physBodyCubes.add(App->physics->AddBody(*cube31, 0));

	cube32 = new Cube(20, 1, 20);
	cube32->SetPos(-48, 12, 578);
	cube32->color = Oxid;
	cubes.add(cube32);
	physBodyCubes.add(App->physics->AddBody(*cube32, 0));

	cube33 = new Cube(20, 1, 20);
	cube33->SetPos(-48, 12, 598);
	cube33->color = Oxid;
	cubes.add(cube33);
	physBodyCubes.add(App->physics->AddBody(*cube33, 0));

	cube34 = new Cube(20, 1, 20);
	cube34->SetPos(-48, 12, 618);
	cube34->color = Oxid;
	cubes.add(cube34);
	physBodyCubes.add(App->physics->AddBody(*cube34, 0));

	cube35 = new Cube(20, 1, 20);
	cube35->SetPos(-48, 12, 638);
	cube35->color = Oxid;
	cubes.add(cube35);
	physBodyCubes.add(App->physics->AddBody(*cube35, 0));

	cube36 = new Cube(20, 1, 20);
	cube36->SetPos(-48, 12, 658);
	cube36->color = Oxid;
	cubes.add(cube36);
	physBodyCubes.add(App->physics->AddBody(*cube36, 0));

	cube37 = new Cube(20, 1, 20);
	cube37->SetPos(-48, 12, 678);
	cube37->color = Oxid;
	cubes.add(cube37);
	physBodyCubes.add(App->physics->AddBody(*cube37, 0));

	cube38 = new Cube(20, 1, 20);
	cube38->SetPos(-48, 12, 698);
	cube38->color = Oxid;
	cubes.add(cube38);
	physBodyCubes.add(App->physics->AddBody(*cube38, 0));

	cube39 = new Cube(20, 1, 20);
	cube39->SetPos(-48, 12, 718);
	cube39->color = Oxid;
	cubes.add(cube39);
	physBodyCubes.add(App->physics->AddBody(*cube39, 0));

	cube40 = new Cube(20, 1, 20);
	cube40->SetPos(-48, 12, 738);
	cube40->color = Oxid;
	cubes.add(cube40);
	physBodyCubes.add(App->physics->AddBody(*cube40, 0));

	cube41 = new Cube(20, 1, 20);
	cube41->SetPos(-78, 12, 738);
	cube41->color = Oxid;
	cubes.add(cube41);
	physBodyCubes.add(App->physics->AddBody(*cube41, 0));
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
	cube21->Render();
	cube22->Render();
	cube23->Render();
	cube24->Render();
	cube25->Render();
	cube26->Render();
	cube27->Render();
	cube28->Render();
	cube29->Render();
	cube30->Render();
	cube31->Render();
	cube32->Render();
	cube33->Render();
	cube34->Render();
	cube35->Render();
	cube36->Render();
	cube37->Render();
	cube38->Render();
	cube39->Render();
	cube40->Render();
	cube41->Render();
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

