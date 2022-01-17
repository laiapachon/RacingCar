#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	car.chassis_size.Set(2, 1, 2);
	car.chassis_offset.Set(0, 2, 0);

	car.ojor_size.Set(0.7, 0.5, 1);
	car.ojor_offset.Set(-0.45, 3.5, 0);

	car.ojol_size.Set(0.7, 0.5, 1);
	car.ojol_offset.Set(0.45, 3.5, 0);

	car.eje_size.Set(0.2, 1.5, 0.2);
	car.eje_offset.Set(0, 3, 0);

	car.brazor_size.Set(0.2, 0.5, 2);
	car.brazor_offset.Set(-1.1, 2.5, 0.3);

	car.brazol_size.Set(0.2, 0.5, 2);
	car.brazol_offset.Set(1.1, 2.5, 0.3);

	car.mass = 1000.0f;
	car.suspensionStiffness = 15.88f;
	car.suspensionCompression = 0.83f;
	car.suspensionDamping = 0.88f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 2.0f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.5f;
	float half_length = car.chassis_size.z*0.5f;
	float half_width_o = car.ojor_size.x * 0.5f;
	float half_length_o = car.ojor_size.z * 0.5f;
	float half_width_ol = car.ojol_size.x * 0.5f;
	float half_length_ol = car.ojol_size.z * 0.5f;
	float half_width_e = car.eje_size.x * 0.5f;
	float half_length_e = car.eje_size.z * 0.5f;
	float half_width_br = car.brazor_size.x * 0.5f;
	float half_length_br = car.brazor_size.z * 0.5f;
	float half_width_bl = car.brazol_size.x * 0.5f;
	float half_length_bl = car.brazol_size.z * 0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 1.5, 10);
	
	// ---------------------------------------------------------
// Window info print
	char title[200];
	//sprintf_s(title, "%.1f Km/h || Time: %.2f",
		//vehicle->GetKmh(), App->scene_intro-> count);
	//App->window->SetTitle(title);
	timer.Start();
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

	

	

	vehicle->Render();
	uint miliseconds = timer.Read() % 1000;
	uint seconds = (timer.Read() / 1000) % 60;
	uint minutes = (timer.Read() / 1000) / 60;
	char title[80];
	

	if (minutes >= 5) {
		timer.Stop();
		sprintf_s(title, "Wasted");
		App->window->SetTitle(title);
		if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT)
		{
			timer.Start();
		}
	}
	else {
		sprintf_s(title, "Time: %02d:%02d:%03d %.1f Km/h", minutes, seconds, miliseconds, vehicle->GetKmh());
		App->window->SetTitle(title);
		if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		{
			acceleration = MAX_ACCELERATION;
		}

		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		{
			if (turn < TURN_DEGREES)
				turn += TURN_DEGREES;
		}

		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		{
			if (turn > -TURN_DEGREES)
				turn -= TURN_DEGREES;
		}

		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		{
			brake = BRAKE_POWER;
		}
		vehicle->ApplyEngineForce(acceleration);
		vehicle->Turn(turn);
		vehicle->Brake(brake);

	}
	
	return UPDATE_CONTINUE;
}

void ModulePlayer::ResetGame()
{
	vehicle->SetVelocity(0, 0, 0);
	mat4x4 transform;
	transform.rotate(0, vec3(0, 0, 1));
	vehicle->SetTransform(&transform);
	vehicle->SetPos(0, 0, 0);
}
//	timer.Start();
//	App->scene_intro->takePlant = false;
//	App->scene_intro->walleFree = true;
//}

//void ModulePlayer::SetWinPosition()
//{
//	vehicle->SetVelocity(0, 0, 0);
//	mat4x4 transform;
//	transform.rotate(0, vec3(0, 0, 1));
//	vehicle->SetTransform(&transform);
//	vehicle->SetPos(0, 0, -90);
//}
