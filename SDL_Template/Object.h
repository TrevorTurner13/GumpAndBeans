#ifndef __OBJECT_H	
#define __DEFINE_H
#include "PhysEntity.h"
#include "BoxCollider.h"
#include "CircleCollider.h"

using namespace SDLFramework;

class Object : public PhysEntity {
private:
	GLTexture* mObjectTexture;

	int mObjectVerticalStrength;
	int mObjectHorizontalStrength;
public:
	Object(GLTexture* texture, BoxCollider* collider, int vertStrength, int horizStrength);
	~Object();

	void RotateTexture();

	void Update() override;
	void Render() override;
};

#endif
