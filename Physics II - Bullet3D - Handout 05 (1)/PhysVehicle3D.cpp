#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Grey;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}
	//chassis
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());

	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	chassis.color = Yellow;

	chassis.Render();

	//ojo derecho
	Cube ojos(info.ojor_size.x, info.ojor_size.y, info.ojor_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&ojos.transform);
	btQuaternion q_o = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset_o(info.ojor_offset.x, info.ojor_offset.y, info.ojor_offset.z);
	offset_o = offset_o.rotate(q_o.getAxis(), q_o.getAngle());

	ojos.transform.M[12] += offset_o.getX();
	ojos.transform.M[13] += offset_o.getY();
	ojos.transform.M[14] += offset_o.getZ();

	ojos.color = Grey;
	ojos.Render();

	//ojo izquierdo
	Cube ojosl(info.ojol_size.x, info.ojol_size.y, info.ojol_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&ojosl.transform);
	btQuaternion q_ol = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset_ol(info.ojol_offset.x, info.ojol_offset.y, info.ojol_offset.z);
	offset_ol = offset_ol.rotate(q_ol.getAxis(), q_ol.getAngle());

	ojosl.transform.M[12] += offset_ol.getX();
	ojosl.transform.M[13] += offset_ol.getY();
	ojosl.transform.M[14] += offset_ol.getZ();

	ojosl.color = Grey;
	ojosl.Render();

	//eje ojo

	Cube ojoseje(info.eje_size.x, info.eje_size.y, info.eje_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&ojoseje.transform);
	btQuaternion q_e = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset_e(info.eje_offset.x, info.eje_offset.y, info.eje_offset.z);
	offset_e = offset_e.rotate(q_e.getAxis(), q_e.getAngle());

	ojoseje.transform.M[12] += offset_e.getX();
	ojoseje.transform.M[13] += offset_e.getY();
	ojoseje.transform.M[14] += offset_e.getZ();

	ojoseje.color = Yellow;
	ojoseje.Render();

	//brazo R

	Cube brazoR(info.brazor_size.x, info.brazor_size.y, info.brazor_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&brazoR.transform);
	btQuaternion q_br = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset_br(info.brazor_offset.x, info.brazor_offset.y, info.brazor_offset.z);
	offset_br = offset_br.rotate(q_br.getAxis(), q_br.getAngle());

	brazoR.transform.M[12] += offset_br.getX();
	brazoR.transform.M[13] += offset_br.getY();
	brazoR.transform.M[14] += offset_br.getZ();

	brazoR.color = Yellow;
	brazoR.Render();

	//brazo L

	Cube brazoL(info.brazol_size.x, info.brazol_size.y, info.brazol_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&brazoL.transform);
	btQuaternion q_bl = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset_bl(info.brazol_offset.x, info.brazol_offset.y, info.brazol_offset.z);
	offset_bl = offset_bl.rotate(q_bl.getAxis(), q_bl.getAngle());

	brazoL.transform.M[12] += offset_bl.getX();
	brazoL.transform.M[13] += offset_bl.getY();
	brazoL.transform.M[14] += offset_bl.getZ();
	brazoL.color = Yellow;

	brazoL.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}


vec3 PhysVehicle3D::GetForwardVector() const
{
	btVector3 a = vehicle->getForwardVector();
	vec3 ret;
	ret.Set(a.getX(), a.getY(), a.getZ());
	return ret;
}


// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}
