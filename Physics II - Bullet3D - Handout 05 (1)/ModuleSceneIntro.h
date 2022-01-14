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
	Cube* cube21;
	Cube* cube22;
	Cube* cube23;
	Cube* cube24;
	Cube* cube25;
	Cube* cube26;
	Cube* cube27;
	Cube* cube28;
	Cube* cube29;
	Cube* cube30;
	Cube* cube31;
	Cube* cube32;
	Cube* cube33;
	Cube* cube34;
	Cube* cube35;
	Cube* cube36;
	Cube* cube37;
	Cube* cube38;
	Cube* cube39;
	Cube* cube40;
	Cube* cube41;
	Cube* cube42;
	Cube* cube43;
	Cube* cube44;
	Cube* cube45;
	Cube* cube46;
	Cube* cube47;
	Cube* cube48;
	Cube* cube49;
	Cube* cube50;
	Cube* cube51;
	Cube* cube52;
	Cube* cube53;
	Cube* cube54;
	Cube* cube55;
	Cube* cube56;
	Cube* cube57;
	Cube* cube58;
	Cube* cube59;
	Cube* cube60;
	Cube* cube61;
	Cube* cube62;
	Cube* cube63;
	Cube* cube64;
	Cube* cube65;
	Cube* cube66;
	Cube* cube67;
	Cube* cube68;
	Cube* cube69;
	Cube* cube70;
	Cube* cube71;
	Cube* cube72;
	Cube* cube73;
	Cube* cube74;
	Cube* cube75;
	Cube* cube76;
	Cube* cube77;
	Cube* cube78;
	Cube* cube79;
	Cube* cube80;
	Cube* cube81;
	Cube* cube82;
	Cube* cube83;
	Cube* cube84;
	Cube* cube85;
	Cube* cube86;
	Cube* cube87;
	Cube* cube88;
	Cube* cube89;
	Cube* cube90;
	Cube* cube91;
	Cube* cube92;
	Cube* cube93;
	Cube* cube94;
	Cube* cube95;
	Cube* cube96;
	Cube* cube97;
	Cube* cube98;
	Cube* cube99;
	Cube* cube100;
	Cube* cube101;
	Cube* cube102;
	Cube* cube103;
	Cube* cube104;
	Cube* cube105;
	Cube* cube106;
	Cube* cube107;
	Cube* cube108;
	Cube* cube109;
	Cube* cube110;
	Cube* cube111;
	Cube* cube112;
	Cube* cube113;
	Cube* cube114;
	Cube* cube115;
	Cube* cube116;
	Cube* cube117;
	Cube* cube118;
	Cube* cube119;
	Cube* cube120;
	Cube* cube121;
	Cube* cube122;
	Cube* cube123;
	Cube* cube124;
	Cube* cube125;
	Cube* cube126;
	Cube* cube127;
	Cube* cube128;
	Cube* cube129;
	Cube* cube130;
	Cube* cube131;
	Cube* cube132;
	Cube* cube133;
	Cube* cube134;
	Cube* cube135;
	Cube* cube136;
	Cube* cube137;
	Cube* cube138;
	Cube* cube139;
	Cube* cube140;
	Cube* cube141;
	Cube* cube142;
	Cube* cube143;
	Cube* cube144;
	Cube* cube145;
	Cube* cube146;
	Cube* cube147;
	Cube* cube148;
	Cube* cube149;
	Cube* cube150;




	//map
	Cube ground;
};