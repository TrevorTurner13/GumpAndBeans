#include "Level1.h"

Level1* Level1::sInstance = nullptr;

Level1* Level1::Instance() {
	if (sInstance == nullptr) {
		sInstance = new Level1();
	}

	return sInstance;
}

void Level1::Release() {
	delete sInstance;
	sInstance = nullptr;
}

Level1::Level1() {

}

Level1::~Level1() {

}

void Level1::Update() {

}

void Level1::Render() {

}