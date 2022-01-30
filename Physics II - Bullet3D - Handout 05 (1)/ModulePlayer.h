#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 50.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();
	void ResetGame();
	bool Start();
	void SetWinPosition();
	void OnCollision(PhysBody3D* body1, PhysBody3D* body2) override;
	update_status Update(float dt);
	bool CleanUp();
	void checkpointReapear(int checkpointPassed);
	//bool TocarPlanta(Plant* plant);

public:

	PhysVehicle3D* vehicle;
	float turn;
	int countInt = 0;
	float acceleration;
	float brake;
	Timer timer;
	float count = 0;

	int f1;
	int Win;
	int buscarplanta;
	int tefaltaplanta;
	int wasted;
	int eevaa;
	int musica;
	bool F1=false;
	bool Winn=false;
	bool Buscarplanta=false;
	bool Tefaltaplanta=false;
	bool Wasted=false;
	bool Eevaa=false;

	int metaFx;
	float positionx = 0;
	float positiony = 0;
	float positionz = 0;
	bool win = false;
	bool planta = false;
	bool nohayplanta = false;
};