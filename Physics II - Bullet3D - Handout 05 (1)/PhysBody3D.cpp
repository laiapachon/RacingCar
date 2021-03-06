#include "PhysBody3D.h"
#include "Globals.h"
#include "Application.h"
#include "Primitive.h"
#include "glmath.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// =================================================
PhysBody3D::PhysBody3D(btRigidBody* body) : body(body)
{}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{
	delete body;
}

// ---------------------------------------------------------
void PhysBody3D::Push(float x, float y, float z)
{
	body->applyCentralImpulse(btVector3(x, y, z));
}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		body->getWorldTransform().getOpenGLMatrix(matrix);
	}
}
 const vec3 PhysBody3D::GetPos() const
{
	btTransform b = body->getWorldTransform();
	btVector3 vec = b.getOrigin();
	vec3 ret;
	ret.Set(vec.getX(), vec.getY(), vec.getZ());
	return ret;
}
// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	if(body != NULL && matrix != NULL)
	{
		btTransform t;
		t.setFromOpenGLMatrix(matrix);
		body->setWorldTransform(t);
	}
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	btTransform t = body->getWorldTransform();
	t.setOrigin(btVector3(x, y, z));
	body->setWorldTransform(t);
}

// ---------------------------------------------------------
void PhysBody3D::SetVelocity(float x, float y, float z)
{
	body->setLinearVelocity(btVector3(x, y, z));
}


void PhysBody3D::SetRotation(btQuaternion q)
{
	btTransform t = body->getWorldTransform();
	t.setRotation(q);
	body->setWorldTransform(t);
}


void PhysBody3D::SetAsSensor(bool is_sensor)
{
	if (this->is_sensor != is_sensor)
	{
		this->is_sensor = is_sensor;
		if (is_sensor == true)
			body->setCollisionFlags(body->getCollisionFlags() | btCollisionObject::CF_NO_CONTACT_RESPONSE);
		else
			body->setCollisionFlags(body->getCollisionFlags() & ~btCollisionObject::CF_NO_CONTACT_RESPONSE);
	}
}
//// ---------------------------------------------------------
btRigidBody* PhysBody3D::GetBody() const
{
return body;
}
/*void PhysBody3D::SetBody(Sphere* primitive, float mass)
{
	SetBody(new btSphereShape(primitive->GetRadius()),
		primitive, mass);
}
void PhysBody3D::SetBody(Cube* primitive, float mass) {
	SetBody(new btBoxShape(btVector3(primitive->GetSize().x * 0.5, primitive->GetSize().y * 0.5, primitive->GetSize().z * 0.5)),
		primitive, mass);
}
void PhysBody3D::SetBody(btCollisionShape* shape, Primitive* parent, float mass)
{
	parentPrimitive = parent;

	colShape = shape;

	btTransform startTransform;
	startTransform.setFromOpenGLMatrix(&parent->transform);

	btVector3 localInertia(0, 0, 0);
	if (mass != 0.f)
		colShape->calculateLocalInertia(mass, localInertia);

	motionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motionState, colShape, localInertia);

	body = new btRigidBody(rbInfo);

	body->setUserPointer(this);

	App->physics->AddBodyToWorld(body);
}*/

void PhysBody3D::SetId(int id)
{
	this->id = id;
}