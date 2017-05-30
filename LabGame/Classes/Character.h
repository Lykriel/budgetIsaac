#ifndef __GAMECHARACTER_H_
#define __GAMECHARACTER_H_

#include "cocos2d.h"
//#include "HelloWorldScene.h"

using namespace cocos2d;

class GameChar
{
private:
	cocos2d::Sprite* mainSprite;
	int intDir;
	int intDirUp;
	float fSpeed;

public:
	void init(const char*, const char*, float, float);
	void MoveChar(int, int);
	void MoveCharByCoord(float, float);
	void Update(float);
	void Stop(int);

	cocos2d::Sprite* getSprite(void) { return mainSprite; }

	cocos2d::GLProgram* CharEffect;
	cocos2d::Vec2 mLoc;
	cocos2d::Vec2 mLocInc;

};

#endif // __GAMECHARACTER_H_