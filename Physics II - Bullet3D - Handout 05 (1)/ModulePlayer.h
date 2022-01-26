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
	bool TocarPlanta(Plant* plant);

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	Timer timer;
	float count = 0;
	int checkpointFx;
	int metaFx;
};