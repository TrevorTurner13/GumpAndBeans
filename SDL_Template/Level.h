#ifndef __LEVEL_H
#define __LEVEL_H
#include "PhysEntity.h"


class Level : public PhysEntity {
private:
	
	int mLevel;

public:
	Level();
	~Level();

	void SetLevelNumber(int level);
	int GetLevelNumber() { return mLevel; }

	void Update() override;
	void Render() override;
};

#endif