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
	cube2->color = Brown1;
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
	cube7->color = Brown1;
	cubes.add(cube7);
	physBodyCubes.add(App->physics->AddBody(*cube7, 0));

	cube8 = new Cube(2, 2, 20);
	cube8->SetPos(-15, 0, 210);
	cube8->color = Oxid;
	cubes.add(cube8);
	physBodyCubes.add(App->physics->AddBody(*cube8, 0));

	cube9 = new Cube(2, 2, 20);
	cube9->SetPos(-15, 0, 240);
	cube9->color = Brown1;
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
	cube12->color = Brown1;
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
	cube17->color = Brown1;
	cubes.add(cube17);
	physBodyCubes.add(App->physics->AddBody(*cube17, 0));

	cube18 = new Cube(2, 2, 10);
	cube18->SetPos(-16, 0, 360);
	cube18->SetRotation(170.0f, { 0,0.5,0 });
	cube18->color = Cobre;
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
	cube21->color = Brown1;
	cubes.add(cube21);
	physBodyCubes.add(App->physics->AddBody(*cube21, 0));

	cube22 = new Cube(2, 2, 10);
	cube22->SetPos(-24, 0, 400);
	cube22->SetRotation(150.0f, { 0,0.5,0 });
	cube22->color = Cobre;
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
	cube24->color = Brown1;
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
	cube26->color = Brown1;
	cubes.add(cube26);
	physBodyCubes.add(App->physics->AddBody(*cube26, 0));

	cube27 = new Cube(20, 1, 20);
	cube27->SetPos(-48, 8.5, 478);
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
	cube29->color = Brown1;
	cubes.add(cube29);
	physBodyCubes.add(App->physics->AddBody(*cube29, 0));


	cube30 = new Cube(20, 1, 20);
	cube30->SetPos(-48, 12, 538);
	cube30->color = Cobre;
	cubes.add(cube30);
	physBodyCubes.add(App->physics->AddBody(*cube30, 0));

	cube31 = new Cube(20, 1, 20);
	cube31->SetPos(-48, 12, 558);
	cube31->color = Cobre;
	cubes.add(cube31);
	physBodyCubes.add(App->physics->AddBody(*cube31, 0));

	cube32 = new Cube(20, 1, 20);
	cube32->SetPos(-48, 12, 578);
	cube32->color = Brown1;
	cubes.add(cube32);
	physBodyCubes.add(App->physics->AddBody(*cube32, 0));

	cube33 = new Cube(20, 1, 20);
	cube33->SetPos(-48, 12, 598);
	cube33->color = Oxid;
	cubes.add(cube33);
	physBodyCubes.add(App->physics->AddBody(*cube33, 0));

	cube34 = new Cube(20, 1, 20);
	cube34->SetPos(-48, 12, 618);
	cube34->color = Cobre;
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
	cube37->color = Cobre;
	cubes.add(cube37);
	physBodyCubes.add(App->physics->AddBody(*cube37, 0));

	cube38 = new Cube(20, 1, 20);
	cube38->SetPos(-48, 12, 698);
	cube38->color = Oxid;
	cubes.add(cube38);
	physBodyCubes.add(App->physics->AddBody(*cube38, 0));

	cube39 = new Cube(20, 1, 20);
	cube39->SetPos(-48, 12, 718);
	cube39->color = Brown1;
	cubes.add(cube39);
	physBodyCubes.add(App->physics->AddBody(*cube39, 0));

	cube40 = new Cube(20, 1, 20);
	cube40->SetPos(-48, 12, 738);
	cube40->color = Cobre;
	cubes.add(cube40);
	physBodyCubes.add(App->physics->AddBody(*cube40, 0));

	cube41 = new Cube(20, 1, 20);
	cube41->SetPos(-68, 12, 738);
	cube41->color = Oxid;
	cubes.add(cube41);
	physBodyCubes.add(App->physics->AddBody(*cube41, 0));

	cube91 = new Cube(20, 1, 20);
	cube91->SetPos(-88, 12, 738);
	cube91->color = Brown1;
	cubes.add(cube91);
	physBodyCubes.add(App->physics->AddBody(*cube91, 0));

	cube92 = new Cube(20, 1, 20);
	cube92->SetPos(-108, 12, 738);
	cube92->color = Brown1;
	cubes.add(cube92);
	physBodyCubes.add(App->physics->AddBody(*cube92, 0));

	cube93 = new Cube(20, 1, 20);
	cube93->SetPos(-128, 12, 738);
	cube93->color = Oxid;
	cubes.add(cube93);
	physBodyCubes.add(App->physics->AddBody(*cube93, 0));

	cube94 = new Cube(20, 1, 20);
	cube94->SetPos(-148, 12, 738);
	cube94->color = Brown1;
	cubes.add(cube94);
	physBodyCubes.add(App->physics->AddBody(*cube94, 0));

	cube95 = new Cube(20, 1, 20);
	cube95->SetPos(-168, 12, 738);
	cube95->color = Brown1;
	cubes.add(cube95);
	physBodyCubes.add(App->physics->AddBody(*cube95, 0));

	cube96 = new Cube(20, 1, 20);
	cube96->SetPos(-188, 12, 738);
	cube96->color = Oxid;
	cubes.add(cube96);
	physBodyCubes.add(App->physics->AddBody(*cube96, 0));

	cube97 = new Cube(20, 1, 20);
	cube97->SetPos(-208, 12, 738);
	cube97->color = Oxid;
	cubes.add(cube97);
	physBodyCubes.add(App->physics->AddBody(*cube97, 0));

	cube98 = new Cube(20, 1, 20);
	cube98->SetPos(-208, 12, 758);
	cube98->color = Oxid;
	cubes.add(cube98);
	physBodyCubes.add(App->physics->AddBody(*cube98, 0));

	cube99 = new Cube(20, 1, 20);
	cube99->SetPos(-208, 12, 778);
	cube99->color = Oxid;
	cubes.add(cube99);
	physBodyCubes.add(App->physics->AddBody(*cube99, 0));

	cube100 = new Cube(20, 1, 20);
	cube100->SetPos(-228, 12, 778);
	cube100->color = Oxid;
	cubes.add(cube100);
	physBodyCubes.add(App->physics->AddBody(*cube100, 0));

	cube101 = new Cube(20, 1, 20);
	cube101->SetPos(-228, 12, 778);
	cube101->color = Oxid;
	cubes.add(cube101);
	physBodyCubes.add(App->physics->AddBody(*cube101, 0));

	cube102 = new Cube(20, 1, 20);
	cube102->SetPos(-248, 12, 778);
	cube102->color = Oxid;
	cubes.add(cube102);
	physBodyCubes.add(App->physics->AddBody(*cube102, 0));

	cube103 = new Cube(20, 1, 20);
	cube103->SetPos(-268, 12, 778);
	cube103->color = Oxid;
	cubes.add(cube103);
	physBodyCubes.add(App->physics->AddBody(*cube103, 0));

	cube104 = new Cube(20, 1, 20);
	cube104->SetPos(-288, 12, 778);
	cube104->color = Oxid;
	cubes.add(cube104);
	physBodyCubes.add(App->physics->AddBody(*cube104, 0));

	cube105 = new Cube(20, 1, 20);
	cube105->SetPos(-308, 12, 778);
	cube105->color = Oxid;
	cubes.add(cube105);
	physBodyCubes.add(App->physics->AddBody(*cube105, 0));

	cube106 = new Cube(20, 1, 20);
	cube106->SetPos(-328, 12, 778);
	cube106->color = Oxid;
	cubes.add(cube106);
	physBodyCubes.add(App->physics->AddBody(*cube106, 0));

	cube107 = new Cube(20, 1, 20);
	cube107->SetPos(-328, 12, 758);
	cube107->color = Oxid;
	cubes.add(cube107);
	physBodyCubes.add(App->physics->AddBody(*cube107, 0));

	cube108 = new Cube(20, 1, 20);
	cube108->SetPos(-328, 12, 738);
	cube108->color = Oxid;
	cubes.add(cube108);
	physBodyCubes.add(App->physics->AddBody(*cube108, 0));

	cube109 = new Cube(20, 1, 20);
	cube109->SetPos(-328, 8, 718);
	cube109->color = Oxid;
	cubes.add(cube109);
	physBodyCubes.add(App->physics->AddBody(*cube109, 0));

	cube110 = new Cube(20, 1, 20);
	cube110->SetPos(-328, 4, 698);
	cube110->color = Oxid;
	cubes.add(cube110);
	physBodyCubes.add(App->physics->AddBody(*cube110, 0));

	cube111 = new Cube(20, 1, 20);
	cube111->SetPos(-328, 2, 678);
	cube111->color = Oxid;
	cubes.add(cube111);
	physBodyCubes.add(App->physics->AddBody(*cube111, 0));

	cube112 = new Cube(20, 1, 20);
	cube112->SetPos(-328, 0, 658);
	cube112->color = Oxid;
	cubes.add(cube112);
	physBodyCubes.add(App->physics->AddBody(*cube112, 0));

	cube113 = new Cube(20, 1, 20);
	cube113->SetPos(-328, 0, 638);
	cube113->color = Oxid;
	cubes.add(cube113);
	physBodyCubes.add(App->physics->AddBody(*cube113, 0));

	cube114 = new Cube(20, 1, 20);
	cube114->SetPos(-328, 0, 618);
	cube114->color = Oxid;
	cubes.add(cube114);
	physBodyCubes.add(App->physics->AddBody(*cube114, 0));

	cube115 = new Cube(20, 1, 20);
	cube115->SetPos(-328, 0, 598);
	cube115->color = Oxid;
	cubes.add(cube115);
	physBodyCubes.add(App->physics->AddBody(*cube115, 0));

	cube116 = new Cube(20, 1, 20);
	cube116->SetPos(-328, 0, 578);
	cube116->color = Oxid;
	cubes.add(cube116);
	physBodyCubes.add(App->physics->AddBody(*cube116, 0));

	cube117 = new Cube(20, 1, 20);
	cube117->SetPos(-328, 0, 558);
	cube117->color = Oxid;
	cubes.add(cube117);
	physBodyCubes.add(App->physics->AddBody(*cube117, 0));

	cube118 = new Cube(20, 1, 20);
	cube118->SetPos(-328, 0, 538);
	cube118->color = Oxid;
	cubes.add(cube118);
	physBodyCubes.add(App->physics->AddBody(*cube118, 0));

	//PAREDES IZQ
	cube42 = new Cube(2, 2, 60);
	cube42->SetPos(14, 2, 70);
	cube42->color = Brown1;
	cubes.add(cube42);
	physBodyCubes.add(App->physics->AddBody(*cube42, 0));

	cube43 = new Cube(2, 2, 60);
	cube43->SetPos(16, 2, 134);
	cube43->color = Oxid;
	cubes.add(cube43);
	physBodyCubes.add(App->physics->AddBody(*cube43, 0));

	cube44 = new Cube(2, 2, 60);
	cube44->SetPos(15, 4, 90);
	cube44->color = Oxid;
	cubes.add(cube44);
	physBodyCubes.add(App->physics->AddBody(*cube44, 0));

	cube45 = new Cube(2, 2, 60);
	cube45->SetPos(16, 4, 28);
	cube45->color = Oxid;;
	cubes.add(cube45);
	physBodyCubes.add(App->physics->AddBody(*cube45, 0));

	cube46 = new Cube(2, 2, 40);
	cube46->SetPos(14,0, 10);
	cube46->color = Cobre;
	cubes.add(cube46);
	physBodyCubes.add(App->physics->AddBody(*cube46, 0));

	cube47 = new Cube(2, 2, 50);
	cube47->SetPos(17, 2, 10);
	cube47->color = Oxid;
	cubes.add(cube47);
	physBodyCubes.add(App->physics->AddBody(*cube47, 0));

	cube50 = new Cube(2, 2, 50);
	cube50->SetPos(15, 6, 10);
	cube50->color = Brown1;
	cubes.add(cube50);
	physBodyCubes.add(App->physics->AddBody(*cube50, 0));

	cube51 = new Cube(2, 2, 50);
	cube51->SetPos(15, 8, 60);
	cube51->color = Oxid;
	cubes.add(cube51);
	physBodyCubes.add(App->physics->AddBody(*cube51, 0));

	cube52 = new Cube(2, 2, 50);
	cube52->SetPos(15, 6, 76);
	cube52->color = Oxid;
	cubes.add(cube52);
	physBodyCubes.add(App->physics->AddBody(*cube52, 0)); 

	cube48 = new Cube(2, 2, 50);
	cube48->SetPos(17, 2, 190);
	cube48->color = Brown1;
	cubes.add(cube48);
	physBodyCubes.add(App->physics->AddBody(*cube48, 0));

	cube49 = new Cube(2, 2, 50);
	cube49->SetPos(17, 4, 190);
	cube49->color = Cobre;
	cubes.add(cube49);
	physBodyCubes.add(App->physics->AddBody(*cube49, 0));

	cube49 = new Cube(2, 2, 50);
	cube49->SetPos(17, 4, 190);
	cube49->color = Oxid;
	cubes.add(cube49);
	physBodyCubes.add(App->physics->AddBody(*cube49, 0));

	cube53 = new Cube(2, 2, 50);
	cube53->SetPos(15, 10, 76);
	cube53->color = Brown1;
	cubes.add(cube53);
	physBodyCubes.add(App->physics->AddBody(*cube53, 0));

	cube54 = new Cube(2, 2, 50);
	cube54->SetPos(15, 10, 20);
	cube54->color = Cobre;;
	cubes.add(cube54);
	physBodyCubes.add(App->physics->AddBody(*cube54, 0));

	cube55 = new Cube(2, 2, 50);
	cube55->SetPos(15, 12, 50);
	cube55->color = Oxid;
	cubes.add(cube55);
	physBodyCubes.add(App->physics->AddBody(*cube55, 0));

	cube56 = new Cube(2, 2, 50);
	cube56->SetPos(15, 10, 140);
	cube56->color = Cobre;
	cubes.add(cube56);
	physBodyCubes.add(App->physics->AddBody(*cube56, 0));

	cube57 = new Cube(2, 2, 50);
	cube57->SetPos(15, 10, 220);
	cube57->color = Brown1;
	cubes.add(cube57);
	physBodyCubes.add(App->physics->AddBody(*cube57, 0));

	cube58 = new Cube(2, 2, 50);
	cube58->SetPos(15, 12, 180);
	cube58->color = Cobre;
	cubes.add(cube58);
	physBodyCubes.add(App->physics->AddBody(*cube58, 0));

	cube59 = new Cube(2, 2, 50);
	cube59->SetPos(14, 12, 98);
	cube59->color = Brown1;
	cubes.add(cube59);
	physBodyCubes.add(App->physics->AddBody(*cube59, 0));

	cube60 = new Cube(2, 2, 50);
	cube60->SetPos(16, 8, 110);
	cube60->color = Cobre;;
	cubes.add(cube60);
	physBodyCubes.add(App->physics->AddBody(*cube60, 0));

	cube61 = new Cube(2, 2, 50);
	cube61->SetPos(16, 8, 190);
	cube61->color = Oxid;
	cubes.add(cube61);
	physBodyCubes.add(App->physics->AddBody(*cube61, 0));

	cube62 = new Cube(2, 2, 50);
	cube62->SetPos(16, 6, 150);
	cube62->color = Cobre;
	cubes.add(cube62);
	physBodyCubes.add(App->physics->AddBody(*cube62, 0));

	cube63 = new Cube(2, 2, 50);
	cube63->SetPos(16, 4, 120);
	cube63->color = Brown1;
	cubes.add(cube63);
	physBodyCubes.add(App->physics->AddBody(*cube63, 0));

	cube64 = new Cube(2, 2, 20);
	cube64->SetPos(16, 10, 100);
	cube64->color = Oxid;
	cubes.add(cube64);
	physBodyCubes.add(App->physics->AddBody(*cube64, 0));

	cube65 = new Cube(2, 2, 50);
	cube65->SetPos(16, 6, 160);
	cube65->color = Cobre;
	cubes.add(cube65);
	physBodyCubes.add(App->physics->AddBody(*cube65, 0));

	//PAREDES DER
	cube66 = new Cube(2, 2, 60);
	cube66->SetPos(-14, 2, 70);
	cube66->color = Oxid;
	cubes.add(cube66);
	physBodyCubes.add(App->physics->AddBody(*cube66, 0));

	cube67 = new Cube(2, 2, 60);
	cube67->SetPos(-16, 2, 134);
	cube67->color = Brown1;
	cubes.add(cube67);
	physBodyCubes.add(App->physics->AddBody(*cube67, 0));

	cube68 = new Cube(2, 2, 60);
	cube68->SetPos(-15, 4, 90);
	cube68->color = Cobre;
	cubes.add(cube68);
	physBodyCubes.add(App->physics->AddBody(*cube68, 0));

	cube69 = new Cube(2, 2, 60);
	cube69->SetPos(-16, 4, 28);
	cube69->color = Oxid;
	cubes.add(cube69);
	physBodyCubes.add(App->physics->AddBody(*cube69, 0));

	cube70 = new Cube(2, 2, 40);
	cube70->SetPos(-14, 0, 10);
	cube70->color = Brown1;
	cubes.add(cube70);
	physBodyCubes.add(App->physics->AddBody(*cube70, 0));

	cube71 = new Cube(2, 2, 50);
	cube71->SetPos(-17, 2, 10);
	cube71->color = Cobre;;
	cubes.add(cube71);
	physBodyCubes.add(App->physics->AddBody(*cube71, 0));

	cube72 = new Cube(2, 2, 50);
	cube72->SetPos(-15, 6, 10);
	cube72->color = Cobre;
	cubes.add(cube72);
	physBodyCubes.add(App->physics->AddBody(*cube72, 0));

	cube73 = new Cube(2, 2, 50);
	cube73->SetPos(-15, 8, 60);
	cube73->color = Brown1;
	cubes.add(cube73);
	physBodyCubes.add(App->physics->AddBody(*cube73, 0));

	cube74 = new Cube(2, 2, 50);
	cube74->SetPos(-15, 6, 76);
	cube74->color = Oxid;
	cubes.add(cube74);
	physBodyCubes.add(App->physics->AddBody(*cube74, 0));

	cube75 = new Cube(2, 2, 50);
	cube75->SetPos(-17, 2, 190);
	cube75->color = Cobre;;
	cubes.add(cube75);
	physBodyCubes.add(App->physics->AddBody(*cube75, 0));

	cube76 = new Cube(2, 2, 50);
	cube76->SetPos(-17, 4, 190);
	cube76->color = Brown1;
	cubes.add(cube76);
	physBodyCubes.add(App->physics->AddBody(*cube76, 0));

	cube77 = new Cube(2, 2, 50);
	cube77->SetPos(-17, 4, 190);
	cube77->color = Cobre;
	cubes.add(cube77);
	physBodyCubes.add(App->physics->AddBody(*cube77, 0));

	cube78 = new Cube(2, 2, 50);
	cube78->SetPos(-15, 10, 76);
	cube78->color = Oxid;
	cubes.add(cube78);
	physBodyCubes.add(App->physics->AddBody(*cube78, 0));

	cube79 = new Cube(2, 2, 50);
	cube79->SetPos(-15, 10, 20);
	cube79->color = Brown1;
	cubes.add(cube79);
	physBodyCubes.add(App->physics->AddBody(*cube79, 0));

	cube80 = new Cube(2, 2, 50);
	cube80->SetPos(-15, 12, 50);
	cube80->color = Oxid;
	cubes.add(cube80);
	physBodyCubes.add(App->physics->AddBody(*cube80, 0));

	cube81 = new Cube(2, 2, 50);
	cube81->SetPos(-15, 10, 140);
	cube81->color = Oxid;
	cubes.add(cube81);
	physBodyCubes.add(App->physics->AddBody(*cube81, 0));

	cube82 = new Cube(2, 2, 50);
	cube82->SetPos(-15, 10, 220);
	cube82->color = Brown1;
	cubes.add(cube82);
	physBodyCubes.add(App->physics->AddBody(*cube82, 0));

	cube83 = new Cube(2, 2, 50);
	cube83->SetPos(-15, 12, 180);
	cube83->color = Cobre;
	cubes.add(cube83);
	physBodyCubes.add(App->physics->AddBody(*cube83, 0));

	cube84 = new Cube(2, 2, 50);
	cube84->SetPos(-14, 12, 98);
	cube84->color = Oxid;
	cubes.add(cube84);
	physBodyCubes.add(App->physics->AddBody(*cube84, 0));

	cube85 = new Cube(2, 2, 50);
	cube85->SetPos(-16, 8, 110);
	cube85->color = Brown1;
	cubes.add(cube85);
	physBodyCubes.add(App->physics->AddBody(*cube85, 0));

	cube86 = new Cube(2, 2, 50);
	cube86->SetPos(-16, 8, 190);
	cube86->color = Cobre;
	cubes.add(cube86);
	physBodyCubes.add(App->physics->AddBody(*cube86, 0));

	cube87 = new Cube(2, 2, 50);
	cube87->SetPos(-16, 6, 150);
	cube87->color = Cobre;
	cubes.add(cube87);
	physBodyCubes.add(App->physics->AddBody(*cube87, 0));

	cube88 = new Cube(2, 2, 50);
	cube88->SetPos(-16, 4, 120);
	cube88->color = Brown1;
	cubes.add(cube88);
	physBodyCubes.add(App->physics->AddBody(*cube88, 0));

	cube89 = new Cube(2, 2, 20);
	cube89->SetPos(-16, 10, 100);
	cube89->color = Cobre;
	cubes.add(cube89);
	physBodyCubes.add(App->physics->AddBody(*cube89, 0));

	cube90 = new Cube(2, 2, 50);
	cube90->SetPos(-16, 6, 160);
	cube90->color = Brown1;
	cubes.add(cube90);
	physBodyCubes.add(App->physics->AddBody(*cube90, 0));


	//FINAL
	cube119 = new Cube(2, 2, 2);
	cube119->SetPos(-328, 0, 518);
	cube119->color = Brown1;
	cubes.add(cube119);
	physBodyCubes.add(App->physics->AddBody(*cube119, 0));

	cube120 = new Cube(2, 2, 2);
	cube120->SetPos(-324, 0, 518);
	cube120->color = Brown1;
	cubes.add(cube120);
	physBodyCubes.add(App->physics->AddBody(*cube120, 0));

	cube121 = new Cube(2, 2, 2);
	cube121->SetPos(-332, 0, 518);
	cube121->color = Brown1;
	cubes.add(cube121);
	physBodyCubes.add(App->physics->AddBody(*cube121, 0));

	cube122 = new Cube(2, 2, 2);
	cube122->SetPos(-328, 0, 514);
	cube122->color = Brown1;
	cubes.add(cube122);
	physBodyCubes.add(App->physics->AddBody(*cube122, 0));

	cube123 = new Cube(0.5, 1.5, 0.5);
	cube123->SetPos(-328, 1, 514);
	cube123->color = Green;
	cubes.add(cube123);
	physBodyCubes.add(App->physics->AddBody(*cube123, 0));

	cube124 = new Cube(0.5, 1.5, 0.5);
	cube124->SetPos(-332, 1, 518);
	cube124->color = Green;
	cubes.add(cube124);
	physBodyCubes.add(App->physics->AddBody(*cube124, 0));

	cube125 = new Cube(0.5, 1.5, 0.5);
	cube125->SetPos(-324, 1, 518);
	cube125->color = Green;
	cubes.add(cube125);
	physBodyCubes.add(App->physics->AddBody(*cube125, 0));

	cube126 = new Cube(0.5, 1.5, 0.5);
	cube126->SetPos(-328, 1, 518);
	cube126->color = Green;
	cubes.add(cube126);
	physBodyCubes.add(App->physics->AddBody(*cube126, 0));

	//CAMINOS TRAMPA
	//1
	cube127 = new Cube(20, 1, 20);
	cube127->SetPos(-308, 12, 798);
	cube127->color = Oxid;
	cubes.add(cube127);
	physBodyCubes.add(App->physics->AddBody(*cube127, 0));

	cube128 = new Cube(20, 1, 20);
	cube128->SetPos(-308, 12, 818);
	cube128->color = Oxid;
	cubes.add(cube128);
	physBodyCubes.add(App->physics->AddBody(*cube128, 0));

	cube129 = new Cube(20, 1, 20);
	cube129->SetPos(-308, 12, 818);
	cube129->color = Oxid;
	cubes.add(cube129);
	physBodyCubes.add(App->physics->AddBody(*cube129, 0));

	cube130 = new Cube(20, 1, 20);
	cube130->SetPos(-308, 12, 838);
	cube130->color = Oxid;
	cubes.add(cube130);
	physBodyCubes.add(App->physics->AddBody(*cube130, 0));

	cube131 = new Cube(20, 1, 20);
	cube131->SetPos(-308, 12, 858);
	cube131->color = Oxid;
	cubes.add(cube131);
	physBodyCubes.add(App->physics->AddBody(*cube131, 0));

	cube132 = new Cube(20, 1, 20);
	cube132->SetPos(-328, 12, 858);
	cube132->color = Oxid;
	cubes.add(cube132);
	physBodyCubes.add(App->physics->AddBody(*cube132, 0));

	cube133 = new Cube(20, 1, 20);
	cube133->SetPos(-348, 12, 858);
	cube133->color = Oxid;
	cubes.add(cube133);
	physBodyCubes.add(App->physics->AddBody(*cube133, 0));

	cube134 = new Cube(20, 1, 20);
	cube134->SetPos(-368, 12, 858);
	cube134->color = Oxid;
	cubes.add(cube134);
	physBodyCubes.add(App->physics->AddBody(*cube134, 0));

	cube135 = new Cube(20, 1, 20);
	cube135->SetPos(-368, 12, 878);
	cube135->color = Oxid;
	cubes.add(cube135);
	physBodyCubes.add(App->physics->AddBody(*cube135, 0));

	cube136 = new Cube(20, 1, 20);
	cube136->SetPos(-388, 12, 878);
	cube136->color = Oxid;
	cubes.add(cube136);
	physBodyCubes.add(App->physics->AddBody(*cube136, 0));

	//2
	cube137 = new Cube(20, 1, 20);
	cube137->SetPos(-228, 12, 798);
	cube137->color = Oxid;
	cubes.add(cube137);
	physBodyCubes.add(App->physics->AddBody(*cube137, 0));

	cube138 = new Cube(20, 1, 20);
	cube138->SetPos(-228, 12, 818);
	cube138->color = Oxid;
	cubes.add(cube138);
	physBodyCubes.add(App->physics->AddBody(*cube138, 0));

	cube139 = new Cube(20, 1, 20);
	cube139->SetPos(-228, 12, 838);
	cube139->color = Oxid;
	cubes.add(cube139);
	physBodyCubes.add(App->physics->AddBody(*cube139, 0));

	cube140 = new Cube(20, 1, 20);
	cube140->SetPos(-228, 12, 858);
	cube140->color = Oxid;
	cubes.add(cube140);
	physBodyCubes.add(App->physics->AddBody(*cube140, 0));

	cube141 = new Cube(20, 1, 20);
	cube141->SetPos(-248, 12, 858);
	cube141->color = Oxid;
	cubes.add(cube141);
	physBodyCubes.add(App->physics->AddBody(*cube141, 0));

	cube142 = new Cube(20, 1, 20);
	cube142->SetPos(-268, 12, 858);
	cube142->color = Oxid;
	cubes.add(cube142);
	physBodyCubes.add(App->physics->AddBody(*cube142, 0));




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
	cube42->Render();
	cube43->Render();
	cube44->Render();
	cube45->Render();
	cube46->Render();
	cube47->Render();
	cube48->Render();
	cube49->Render();
	cube50->Render();
	cube51->Render();
	cube52->Render();
	cube53->Render();
	cube54->Render();
	cube55->Render();
	cube56->Render();
	cube57->Render();
	cube58->Render();
	cube59->Render();
	cube60->Render();
	cube61->Render();
	cube62->Render();
	cube63->Render();
	cube64->Render();
	cube65->Render();
	cube66->Render();
	cube67->Render();
	cube68->Render();
	cube69->Render();
	cube70->Render();
	cube71->Render();
	cube72->Render();
	cube73->Render();
	cube74->Render();
	cube75->Render();
	cube76->Render();
	cube77->Render();
	cube78->Render();
	cube79->Render();
	cube80->Render();
	cube81->Render();
	cube82->Render();
	cube83->Render();
	cube84->Render();
	cube85->Render();
	cube86->Render();
	cube87->Render();
	cube88->Render();
	cube89->Render();
	cube90->Render();
	cube91->Render();
	cube92->Render();
	cube93->Render();
	cube94->Render();
	cube95->Render();
	cube96->Render();
	cube97->Render();
	cube98->Render();
	cube99->Render();
	cube100->Render();
	cube101->Render();
	cube102->Render();
	cube103->Render();
	cube104->Render();
	cube105->Render();
	cube106->Render();
	cube107->Render();
	cube108->Render();
	cube109->Render();
	cube110->Render();
	cube111->Render();
	cube112->Render();
	cube113->Render();
	cube114->Render();
	cube115->Render();
	cube116->Render();
	cube117->Render();
	cube118->Render();
	cube119->Render();
	cube120->Render();
	cube121->Render();
	cube122->Render();
	cube123->Render();
	cube124->Render();
	cube125->Render();
	cube126->Render();
	cube127->Render();
	cube128->Render();
	cube129->Render();
	cube130->Render();
	cube131->Render();
	cube132->Render();
	cube133->Render();
	cube134->Render();
	cube135->Render();
	cube136->Render();
	cube137->Render();
	cube138->Render();
	cube139->Render();
	cube140->Render();
	cube141->Render();
	cube142->Render();

	// Plants Render
	/*if (!pickUpPatient1 && !inSceneWin)
	{
		patients.head[0].Render();
		patients.body[0]->Render();
	}
	if (!pickUpPatient2 && pickUpPatient1 && ambulanceFree)
	{
		patients.head[1].Render();
		patients.body[1]->Render();
	}
	if (!pickUpPatient3 && pickUpPatient2 && ambulanceFree)
	{
		patients.head[2].Render();
		patients.body[2]->Render();
	}
	if (!pickUpPatient4 && pickUpPatient3 && ambulanceFree)
	{
		patients.head[3].Render();
		patients.body[3]->Render();
	}
	if (!pickUpPatient5 && pickUpPatient4 && ambulanceFree)
	{
		patients.head[4].Render();
		patients.body[4]->Render();
	}*/

	/*if (countHospitalPatients == 5 && countPatients == 5)
	{
		winDuration = winTimer.Read() * 0.001f;
		Win();
		for (uint i = 0; i < winPrimitives.Count(); i++)
			winPrimitives[i]->Update();
	}*/

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	// All cases for collisions with patients or hospital sensor
	/*if (body1->is_sensor && !inSceneWin)
	{
		if (body1 == patients.phys_patients[0] && ambulanceFree)
		{
			if (countPatients < 1)
			{
				countPatients = 1;
				pickUpPatient1 = true;
				ambulanceFree = false;
				App->audio->PlayFx(pickupFx);
			}
		}

		if (body1 == patients.phys_patients[1] && pickUpPatient1 && ambulanceFree)
		{
			if (countPatients < 2)
			{
				pickUpPatient2 = true;
				ambulanceFree = false;
				App->audio->PlayFx(pickupFx);
				countPatients = 2;
			}
		}
		if (body1 == patients.phys_patients[2] && pickUpPatient2 && ambulanceFree)
		{
			if (countPatients < 3)
			{
				pickUpPatient3 = true;
				ambulanceFree = false;
				App->audio->PlayFx(pickupFx);
				countPatients = 3;
			}
		}
		if (body1 == patients.phys_patients[3] && pickUpPatient3 && ambulanceFree)
		{
			if (countPatients < 4)
			{
				pickUpPatient4 = true;
				ambulanceFree = false;
				App->audio->PlayFx(pickupFx);
				countPatients = 4;
			}
		}
		if (body1 == patients.phys_patients[4] && pickUpPatient4 && ambulanceFree)
		{
			if (countPatients < 5)
			{
				pickUpPatient5 = true;
				ambulanceFree = false;
				App->audio->PlayFx(pickupFx);
				countPatients = 5;
			}
		}
		if (body1 == hospitalSensor && !ambulanceFree)
		{
			ambulanceFree = true;
			App->audio->StopFx(App->player->sirenFx);
			App->audio->PlayFx(hospitalFx);


			if (countHospitalPatients < 1 && pickUpPatient1) countHospitalPatients = 1;
			if (countHospitalPatients < 2 && pickUpPatient2) countHospitalPatients = 2;
			if (countHospitalPatients < 3 && pickUpPatient3) countHospitalPatients = 3;
			if (countHospitalPatients < 4 && pickUpPatient4) countHospitalPatients = 4;
			if (countHospitalPatients < 5 && pickUpPatient5)
			{
				countHospitalPatients = 5;
				App->audio->StopMusic();
				App->audio->PlayMusic("Assets/Sound/victory.ogg");
				App->player->SetWinPosition();
				inSceneWin = true;
				winTimer.Start();
			}
		}
	}*/
}

update_status ModuleSceneIntro::PostUpdate(float dt)
{
	for (uint i = 0; i < primitives.Count(); i++)
		primitives[i]->Render();
	
	if (/*countHospitalPatients == 5 &&*/ countPlants == 5)
	{
		for (uint i = 0; i < winPrimitives.Count(); i++)
			winPrimitives[i]->Render();
	}

	return UPDATE_CONTINUE;
}


void ModuleSceneIntro::CreatePlant(const vec3 pos, Color pColorHead, Color pColorBody)
{
	// Create sphere and cube to render a patient

	Cube* c;
	c = new Cube(0.5, 2, 0.5);
	c->color = pColorBody;
	c->SetPos(pos.x, pos.y + 1.5, pos.z);
	plants.body.PushBack(c);

	// Create a sensor to be able to pick patients
	Cube* sensor;
	sensor = new Cube(1, 3, 1);
	sensor->SetPos(pos.x, pos.y + 2, pos.z);
	//plants.phys_plants.PushBack(App->physics->AddBody(*sensor, this, 0.0f, true));
}
