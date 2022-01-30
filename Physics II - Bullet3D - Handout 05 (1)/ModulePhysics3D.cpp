#include "Globals.h"
#include "Application.h"
#include "ModulePhysics3D.h"
#include "PhysBody3D.h"
#include "PhysVehicle3D.h"
#include "Primitive.h"

#ifdef _DEBUG
	#pragma comment (lib, "Bullet/libx86/BulletDynamics_debug.lib")
	#pragma comment (lib, "Bullet/libx86/BulletCollision_debug.lib")
	#pragma comment (lib, "Bullet/libx86/LinearMath_debug.lib")
#else
	#pragma comment (lib, "Bullet/libx86/BulletDynamics.lib")
	#pragma comment (lib, "Bullet/libx86/BulletCollision.lib")
	#pragma comment (lib, "Bullet/libx86/LinearMath.lib")
#endif

ModulePhysics3D::ModulePhysics3D(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	debug = true;

	collision_conf = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collision_conf);
	broad_phase = new btDbvtBroadphase();
	solver = new btSequentialImpulseConstraintSolver();
	debug_draw = new DebugDrawer();
}

// Destructor
ModulePhysics3D::~ModulePhysics3D()
{
	delete debug_draw;
	delete solver;
	delete broad_phase;
	delete dispatcher;
	delete collision_conf;
}

// Render not available yet----------------------------------
bool ModulePhysics3D::Init()
{
	LOG("Creating 3D Physics simulation");
	bool ret = true;

	return ret;
}

// ---------------------------------------------------------
bool ModulePhysics3D::Start()
{
	LOG("Creating Physics environment");

	world = new btDiscreteDynamicsWorld(dispatcher, broad_phase, solver, collision_conf);
	world->setDebugDrawer(debug_draw);
	world->setGravity(GRAVITY);
	vehicle_raycaster = new btDefaultVehicleRaycaster(world);

	// Big plane as ground
	//{
	//	btCollisionShape* colShape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);

	//	btDefaultMotionState* myMotionState = new btDefaultMotionState();
	//	btRigidBody::btRigidBodyConstructionInfo rbInfo(0.0f, myMotionState, colShape);

	//	btRigidBody* body = new btRigidBody(rbInfo);
	//	world->addRigidBody(body);
	//}

	return true;
}

// ---------------------------------------------------------
update_status ModulePhysics3D::PreUpdate(float dt)
{
	world->stepSimulation(dt, 15);

	int numManifolds = world->getDispatcher()->getNumManifolds();
	for(int i = 0; i<numManifolds; i++)
	{
		btPersistentManifold* contactManifold = world->getDispatcher()->getManifoldByIndexInternal(i);
		btCollisionObject* obA = (btCollisionObject*)(contactManifold->getBody0());
		btCollisionObject* obB = (btCollisionObject*)(contactManifold->getBody1());

		int numContacts = contactManifold->getNumContacts();
		if(numContacts > 0)
		{
			PhysBody3D* pbodyA = (PhysBody3D*)obA->getUserPointer();
			PhysBody3D* pbodyB = (PhysBody3D*)obB->getUserPointer();

			if(pbodyA && pbodyB)
			{
				p2List_item<Module*>* item = pbodyA->collision_listeners.getFirst();
				while(item)
				{
					item->data->OnCollision(pbodyA, pbodyB);
					item = item->next;
				}

				item = pbodyB->collision_listeners.getFirst();
				while(item)
				{
					item->data->OnCollision(pbodyB, pbodyA);
					item = item->next;
				}
			}
		}
	}

	return UPDATE_CONTINUE;
}

// ---------------------------------------------------------
update_status ModulePhysics3D::Update(float dt)
{
	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(debug == true)
	{
		world->debugDrawWorld();

		// Render vehicles
		p2List_item<PhysVehicle3D*>* item = vehicles.getFirst();
		while(item)
		{
			item->data->Render();
			item = item->next;
		}

		if(App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		{
			Sphere s(1);
			s.SetPos(App->camera->Position.x, App->camera->Position.y, App->camera->Position.z);
			float force = 30.0f;
			AddBody(s)->Push(-(App->camera->Z.x * force), -(App->camera->Z.y * force), -(App->camera->Z.z * force));
		}
	}

	return UPDATE_CONTINUE;
}

// ---------------------------------------------------------
update_status ModulePhysics3D::PostUpdate(float dt)
{
	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePhysics3D::CleanUp()
{
	LOG("Destroying 3D Physics simulation");

	// Remove from the world all collision bodies
	for(int i = world->getNumCollisionObjects() - 1; i >= 0; i--)
	{
		btCollisionObject* obj = world->getCollisionObjectArray()[i];
		world->removeCollisionObject(obj);
	}

	for(p2List_item<btTypedConstraint*>* item = constraints.getFirst(); item; item = item->next)
	{
		world->removeConstraint(item->data);
		delete item->data;
	}
	
	constraints.clear();

	for(p2List_item<btDefaultMotionState*>* item = motions.getFirst(); item; item = item->next)
		delete item->data;

	motions.clear();

	for(p2List_item<btCollisionShape*>* item = shapes.getFirst(); item; item = item->next)
		delete item->data;

	shapes.clear();

	for(p2List_item<PhysBody3D*>* item = bodies.getFirst(); item; item = item->next)
		delete item->data;

	bodies.clear();

	for(p2List_item<PhysVehicle3D*>* item = vehicles.getFirst(); item; item = item->next)
		delete item->data;

	vehicles.clear();

	delete vehicle_raycaster;
	delete world;

	return true;
}

// ---------------------------------------------------------
PhysBody3D* ModulePhysics3D::AddBody(const Sphere& sphere, float mass)
{
	btCollisionShape* colShape = new btSphereShape(sphere.radius);
	shapes.add(colShape);

	btTransform startTransform;
	startTransform.setFromOpenGLMatrix(&sphere.transform);

	btVector3 localInertia(0, 0, 0);
	if(mass != 0.f)
		colShape->calculateLocalInertia(mass, localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	motions.add(myMotionState);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);

	btRigidBody* body = new btRigidBody(rbInfo);
	PhysBody3D* pbody = new PhysBody3D(body);

	pbody->SetId(0);

	body->setUserPointer(pbody);
	world->addRigidBody(body);
	bodies.add(pbody);

	return pbody;
}


// ---------------------------------------------------------
PhysBody3D* ModulePhysics3D::AddBody(const Cube& cube, float mass)
{
	btCollisionShape* colShape = new btBoxShape(btVector3(cube.size.x*0.5f, cube.size.y*0.5f, cube.size.z*0.5f));
	shapes.add(colShape);

	btTransform startTransform;
	startTransform.setFromOpenGLMatrix(&cube.transform);

	btVector3 localInertia(0, 0, 0);
	if(mass != 0.f)
		colShape->calculateLocalInertia(mass, localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	motions.add(myMotionState);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);

	btRigidBody* body = new btRigidBody(rbInfo);
	PhysBody3D* pbody = new PhysBody3D(body);

	pbody->SetId(0);

	body->setUserPointer(pbody);
	world->addRigidBody(body);
	bodies.add(pbody);

	return pbody;
}

// ---------------------------------------------------------
PhysBody3D* ModulePhysics3D::AddBody(const Cylinder& cylinder, float mass)
{
	btCollisionShape* colShape = new btCylinderShapeX(btVector3(cylinder.height*0.5f, cylinder.radius, 0.0f));
	shapes.add(colShape);

	btTransform startTransform;
	startTransform.setFromOpenGLMatrix(&cylinder.transform);

	btVector3 localInertia(0, 0, 0);
	if(mass != 0.f)
		colShape->calculateLocalInertia(mass, localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	motions.add(myMotionState);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);

	btRigidBody* body = new btRigidBody(rbInfo);
	PhysBody3D* pbody = new PhysBody3D(body);

	pbody->SetId(0);

	body->setUserPointer(pbody);
	world->addRigidBody(body);
	bodies.add(pbody);

	return pbody;
}

// ---------------------------------------------------------
PhysVehicle3D* ModulePhysics3D::AddVehicle(const VehicleInfo& info)
{
	//CHASSIS
	btCompoundShape* comShape = new btCompoundShape();
	shapes.add(comShape);

	btCollisionShape* colShape = new btBoxShape(btVector3(info.chassis_size.x*0.5f, info.chassis_size.y*0.5f, info.chassis_size.z*0.5f));
	shapes.add(colShape);
	

	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(btVector3(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z));

	comShape->addChildShape(trans, colShape);

	//OJO DERECHO
	btCollisionShape* colShape_o = new btBoxShape(btVector3(info.ojor_size.x * 0.5f, info.ojor_size.y * 0.5f, info.ojor_size.z * 0.5f));
	shapes.add(colShape_o);


	btTransform trans_o;
	trans_o.setIdentity();
	trans_o.setOrigin(btVector3(info.ojor_offset.x, info.ojor_offset.y, info.ojor_offset.z));

	comShape->addChildShape(trans_o, colShape_o);

	//OJO IZQUIERDO
	btCollisionShape* colShape_oL = new btBoxShape(btVector3(info.ojol_size.x * 0.5f, info.ojol_size.y * 0.5f, info.ojol_size.z * 0.5f));
	shapes.add(colShape_oL);


	btTransform trans_oL;
	trans_oL.setIdentity();
	trans_oL.setOrigin(btVector3(info.ojol_offset.x, info.ojol_offset.y, info.ojol_offset.z));

	comShape->addChildShape(trans_oL, colShape_oL);

	//eje ojos
	btCollisionShape* colShape_e = new btBoxShape(btVector3(info.eje_size.x * 0.5f, info.eje_size.y * 0.5f, info.eje_size.z * 0.5f));
	shapes.add(colShape_e);


	btTransform trans_e;
	trans_e.setIdentity();
	trans_e.setOrigin(btVector3(info.eje_offset.x, info.eje_offset.y, info.eje_offset.z));

	comShape->addChildShape(trans_e, colShape_e);


	//brazoR
	btCollisionShape* colShape_br = new btBoxShape(btVector3(info.brazor_size.x * 0.5f, info.brazor_size.y * 0.5f, info.brazor_size.z * 0.5f));
	shapes.add(colShape_br);


	btTransform trans_br;
	trans_br.setIdentity();
	trans_br.setOrigin(btVector3(info.brazor_offset.x, info.brazor_offset.y, info.brazor_offset.z));

	comShape->addChildShape(trans_br, colShape_br);

	//brazoL
	btCollisionShape* colShape_bl = new btBoxShape(btVector3(info.brazol_size.x * 0.5f, info.brazol_size.y * 0.5f, info.brazol_size.z * 0.5f));
	shapes.add(colShape_bl);


	btTransform trans_bl;
	trans_bl.setIdentity();
	trans_bl.setOrigin(btVector3(info.brazol_offset.x, info.brazol_offset.y, info.brazol_offset.z));

	comShape->addChildShape(trans_bl, colShape_bl);




	btTransform startTransform;
	startTransform.setIdentity();

	btVector3 localInertia(0, 0, 0);
	comShape->calculateLocalInertia(info.mass, localInertia);

	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(info.mass, myMotionState, comShape, localInertia);

	btRigidBody* body = new btRigidBody(rbInfo);
	body->setContactProcessingThreshold(BT_LARGE_FLOAT);
	body->setActivationState(DISABLE_DEACTIVATION);

	world->addRigidBody(body);

	btRaycastVehicle::btVehicleTuning tuning;
	tuning.m_frictionSlip = info.frictionSlip;
	tuning.m_maxSuspensionForce = info.maxSuspensionForce;
	tuning.m_maxSuspensionTravelCm = info.maxSuspensionTravelCm;
	tuning.m_suspensionCompression = info.suspensionCompression;
	tuning.m_suspensionDamping = info.suspensionDamping;
	tuning.m_suspensionStiffness = info.suspensionStiffness;

	btRaycastVehicle* vehicle = new btRaycastVehicle(tuning, body, vehicle_raycaster);

	vehicle->setCoordinateSystem(0, 1, 2);

	for(int i = 0; i < info.num_wheels; ++i)
	{
		btVector3 conn(info.wheels[i].connection.x, info.wheels[i].connection.y, info.wheels[i].connection.z);
		btVector3 dir(info.wheels[i].direction.x, info.wheels[i].direction.y, info.wheels[i].direction.z);
		btVector3 axis(info.wheels[i].axis.x, info.wheels[i].axis.y, info.wheels[i].axis.z);

		vehicle->addWheel(conn, dir, axis, info.wheels[i].suspensionRestLength, info.wheels[i].radius, tuning, info.wheels[i].front);
	}
	// ---------------------



	PhysVehicle3D* pvehicle = new PhysVehicle3D(body, vehicle, info);
	pvehicle->SetId(0);
	world->addVehicle(vehicle);
	vehicles.add(pvehicle);

	return pvehicle;
}

// ---------------------------------------------------------
void ModulePhysics3D::AddConstraintP2P(PhysBody3D& bodyA, PhysBody3D& bodyB, const vec3& anchorA, const vec3& anchorB)
{
	btTypedConstraint* p2p = new btPoint2PointConstraint(
		*(bodyA.body), 
		*(bodyB.body), 
		btVector3(anchorA.x, anchorA.y, anchorA.z), 
		btVector3(anchorB.x, anchorB.y, anchorB.z));
	world->addConstraint(p2p);
	constraints.add(p2p);
	p2p->setDbgDrawSize(2.0f);
}

void ModulePhysics3D::AddConstraintHinge(PhysBody3D& bodyA, PhysBody3D& bodyB, const vec3& anchorA, const vec3& anchorB, const vec3& axisA, const vec3& axisB, bool disable_collision)
{
	btHingeConstraint* hinge = new btHingeConstraint(
		*(bodyA.body), 
		*(bodyB.body), 
		btVector3(anchorA.x, anchorA.y, anchorA.z),
		btVector3(anchorB.x, anchorB.y, anchorB.z),
		btVector3(axisA.x, axisA.y, axisA.z), 
		btVector3(axisB.x, axisB.y, axisB.z));

	world->addConstraint(hinge, disable_collision);
	constraints.add(hinge);
	hinge->setDbgDrawSize(2.0f);
}

void ModulePhysics3D::Drag(const VehicleInfo& info, PhysVehicle3D& vehicle)
{
	float cd = 0.8;
	float densidada = 0.18;
	float superficie = 24;

	if (DragEnabled)
	{
		if (vehicle.GetForwardVector().x >= 0)
		{
			Fdx = -0.5 * densidada * vehicle.GetKmh() * superficie * cd;
		}
		else if (vehicle.GetForwardVector().x < 0)
		{
			Fdx = 0.5 * densidada * vehicle.GetKmh() * superficie * cd;
		}
		else
		{
			Fdx = 0;
		}

		if (vehicle.GetForwardVector().y >= 0)
		{
			Fdy = -0.5 * densidada * vehicle.GetKmh() * superficie * cd;
		}
		else if (vehicle.GetForwardVector().y < 0)
		{
			Fdy = 0.5 * densidada * vehicle.GetKmh() * superficie * cd;
		}
		else
		{
			Fdy = 0;
		}
		
		if (vehicle.GetForwardVector().z >= 0)
		{
			Fdz = -0.5 * densidada * vehicle.GetKmh() * superficie * cd;
		}
		else if (vehicle.GetForwardVector().z < 0)
		{
			Fdz = 0.5 * densidada * vehicle.GetKmh() * superficie * cd;
		}
		else
		{
			Fdz = 0;
		}
	}
	else
	{
		Fdx = 0;
		Fdy = 0;
		Fdz = 0;
	}
}
void ModulePhysics3D::Lift(const VehicleInfo& info, PhysVehicle3D& vehicle)
{
	float cs = 0.01;
	float densidada = 0.18;
	float area = 24;

	if (DragEnabled)
	{
		if (vehicle.GetForwardVector().x >= 0)
		{
			Flx = -0.5 * densidada * vehicle.GetKmh() * area * cs;
		}
		else if (vehicle.GetForwardVector().x < 0)
		{
			Flx = 0.5 * densidada * vehicle.GetKmh() * area * cs;
		}
		else
		{
			Flx = 0;
		}

		if (vehicle.GetForwardVector().y >= 0)
		{
			Fly = -0.5 * densidada * vehicle.GetKmh() * area * cs;
		}
		else if (vehicle.GetForwardVector().y < 0)
		{
			Fly = 0.5 * densidada * vehicle.GetKmh() * area * cs;
		}
		else
		{
			Fly = 0;
		}

		if (vehicle.GetForwardVector().z >= 0)
		{
			Flz = -0.5 * densidada * vehicle.GetKmh() * area * cs;
		}
		else if (vehicle.GetForwardVector().z < 0)
		{
			Flz = 0.5 * densidada * vehicle.GetKmh() * area * cs;
		}
		else
		{
			Flz = 0;
		}
	}
	else
	{
		Flx = 0;
		Fly = 0;
		Flz = 0;
	}
}



// =============================================
void DebugDrawer::drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
{
	line.origin.Set(from.getX(), from.getY(), from.getZ());
	line.destination.Set(to.getX(), to.getY(), to.getZ());
	line.color.Set(color.getX(), color.getY(), color.getZ());
	line.Render();
}

void DebugDrawer::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color)
{
	point.transform.translate(PointOnB.getX(), PointOnB.getY(), PointOnB.getZ());
	point.color.Set(color.getX(), color.getY(), color.getZ());
	point.Render();
}

void DebugDrawer::reportErrorWarning(const char* warningString)
{
	LOG("Bullet warning: %s", warningString);
}

void DebugDrawer::draw3dText(const btVector3& location, const char* textString)
{
	LOG("Bullet draw text: %s", textString);
}

void DebugDrawer::setDebugMode(int debugMode)
{
	mode = (DebugDrawModes) debugMode;
}

int	 DebugDrawer::getDebugMode() const
{
	return mode;
}
