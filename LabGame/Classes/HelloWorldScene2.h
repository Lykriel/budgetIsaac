#ifndef __HELLOWORLD_SCENE2_H__
#define __HELLOWORLD_SCENE2_H__

#include "cocos2d.h"
#include "Character.h"

using namespace cocos2d;

class HelloWorld2 : public cocos2d::CCLayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	virtual void onKeyPressed(EventKeyboard::KeyCode, Event*);
	virtual void onKeyReleased(EventKeyboard::KeyCode, Event*);
	virtual void onMouseDown(EventMouse*);

	GameChar* getChar(void);

	virtual void update(float) override;

	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld2);

private:
	GameChar mainChar;

	GLProgram* proPostProcess;
	RenderTexture *rendtex;
	Sprite* rendtexSprite;
};

#endif // __HELLOWORLD_SCENE2_H__
