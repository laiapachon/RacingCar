#ifndef __PhysBody3D_H__
#define __PhysBody3D_H__

#include "p2List.h"

class btQuaternion;
class btRigidBody;
class Module;



// =================================================
struct PhysBody3D
{
	friend class ModulePhysics3D;
public:
	PhysBody3D(btRigidBody* body);
	~PhysBody3D();

	void Push(float x, float y, float z);
	void GetTransform(float* matrix) const;
	void SetTransform(const float* matrix) const;
	void SetPos(float x, float y, float z);
	void SetVelocity(float x, float y, float z);
	void SetRotation(btQuaternion q);
	btRigidBody* GetBody() const;
	/*void SetBody(Sphere* primitive, float mass);
	void SetBody(Cube* primitive, float mass);
	void SetBody(btCollisionShape* shape, Primitive* parent, float mass);*/
	void SetAsSensor(bool is_sensor);
	void SetId(int id);
	
private:
	
	
public:
	//const vec3 GetPos() const;
	btRigidBody* body = nullptr;
	p2List<Module*> collision_listeners;
	bool is_sensor = false;
	int id;
};

#endif // __PhysBody3D_H__