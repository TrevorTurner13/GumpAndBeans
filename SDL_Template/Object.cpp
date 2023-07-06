#include "Object.h"

Object::Object(GLTexture* texture, BoxCollider* collider, int vertStrength, int horizStrength) {
	mObjectTexture = texture;
	mObjectTexture->Parent(this);

	AddCollider(collider, Vector2(Local));

	mObjectVerticalStrength = vertStrength;
	mObjectHorizontalStrength = horizStrength;
	SetStrength(vertStrength, horizStrength);
}

Object::~Object() {
	delete mObjectTexture;
	mObjectTexture = nullptr;
}


void Object::Update() {

}

void Object::Render() {
	mObjectTexture->Render();

	PhysEntity::Render();
}

void Object::RotateTexture(float degrees) {
	mObjectTexture->Rotate(degrees);
}