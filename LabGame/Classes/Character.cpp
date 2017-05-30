#include "Character.h"

void GameChar::init(const char* chSource, const char* chName, float fX, float fY)
{
	mainSprite = Sprite::create(chSource);
	mainSprite->setAnchorPoint(Vec2(0, 0));
	mainSprite->setPosition(fX, fY);
	mainSprite->setName(chName);
	intDir = 0;
	intDirUp = 0;
	fSpeed = 0.01f;

	mLoc.set(.5f, .5f);
	mLocInc.set(.005f, .01f);

	CharEffect = new GLProgram();
	CharEffect->initWithFilenames("Basic.vsh", "CharEffect.fsh");
	CharEffect->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	CharEffect->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	CharEffect->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
	CharEffect->link();
	CharEffect->updateUniforms();

	GLProgramState* state = GLProgramState::getOrCreateWithGLProgram(CharEffect);
	mainSprite->setGLProgram(CharEffect);
	mainSprite->setGLProgramState(state);
	state->setUniformVec2("loc", mLoc);
}

void GameChar::MoveChar(int DirX, int DirY)
{
	intDir += DirX;
	intDirUp += DirY;
	//mainSprite->stopAllActions();

	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(3);
	if (intDirUp != 0)
	{
		if (intDirUp < 0)
		{
			animFrames.pushBack(SpriteFrame::create("Player_Front1.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Front2.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Front3.png", Rect(0, 0, 59, 81)));
		}
		else if (intDirUp > 0)
		{
			animFrames.pushBack(SpriteFrame::create("Player_Front1.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Front2.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Front3.png", Rect(0, 0, 59, 81)));
		}
	}
	else
	{
		if (intDir > 0 && intDirUp == 0)
		{
			animFrames.pushBack(SpriteFrame::create("Player_Side1.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Side2.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Side3.png", Rect(0, 0, 59, 81)));
		}
		else if (intDirUp == 0)
		{
			animFrames.pushBack(SpriteFrame::create("Player_Side1.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Side2.png", Rect(0, 0, 59, 81)));
			animFrames.pushBack(SpriteFrame::create("Player_Side3.png", Rect(0, 0, 59, 81)));
		}
	}
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	Animate* animate = Animate::create(animation);
	mainSprite->runAction(RepeatForever::create(animate));
}

void GameChar::Stop(int a)
{
	if (a == 1)
		intDir = 0;
	else
		intDirUp = 0;

	mainSprite->stopAllActions();
	// now lets animate the sprite we moved

	//Vector < SpriteFrame* > animFrames;
	//animFrames.reserve(4);
	//if (intDir == 0)
	//{
	//	animFrames.pushBack(SpriteFrame::create("Blue_Front2.png", Rect(0, 0, 65, 81)));
	//	animFrames.pushBack(SpriteFrame::create("Blue_Front1.png", Rect(0, 0, 65, 81)));
	//	animFrames.pushBack(SpriteFrame::create("Blue_Front3.png", Rect(0, 0, 65, 81)));
	//	animFrames.pushBack(SpriteFrame::create("Blue_Front1.png", Rect(0, 0, 65, 81)));
	//}

	//// create the animation out of the frames
	//Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	//Animate* animateIdle = Animate::create(animation);

	//// run it and repeat it forever
	//mainSprite->runAction(RepeatForever::create(animateIdle));

}

void GameChar::MoveCharByCoord(float fX, float fY)
{
	mainSprite->stopAllActions();
	float diffX = fX - mainSprite->getPosition().x;
	float diffY = fY - mainSprite->getPosition().y;
	//Vec2 vec = Vec2(diffX, diffY);
	auto vec = Vec2(diffX, diffY);
	auto moveEvent = MoveBy::create(vec.length()*fSpeed, vec);
	//mainSprite->runAction(moveEvent);

	//auto callbackStop = CallFunc::create([]()
	//{
	//	auto scene = Director::getInstance()->getRunningScene();
	//	auto layer = scene->getChildByTag(999);
	//	HelloWorld* helloLayer = dynamic_cast<HelloWorld*>(layer);
	//	if (helloLayer != NULL)
	//		helloLayer->getChar()->Stop();
	//});
	//auto seq = Sequence::create(moveEvent, callbackStop, nullptr);
	//mainSprite->runAction(seq);
	
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(4);
	animFrames.pushBack(SpriteFrame::create("Player_Front2.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Player_Front1.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Player_Front3.png", Rect(0, 0, 65, 81)));
	animFrames.pushBack(SpriteFrame::create("Player_Front1.png", Rect(0, 0, 65, 81)));
	
	// create the animation out of the frames
	Animation* animation = Animation::createWithSpriteFrames(animFrames, 0.5f);
	Animate* animateIdle = Animate::create(animation);
	
	// run it and repeat it forever
	mainSprite->runAction(RepeatForever::create(animateIdle));
}

void GameChar::Update(float delta)
{
	if (intDir != 0)
	{
		auto moveEvent = MoveBy::create(0.0f, Vec2(50.0f, 0.f) * intDir * delta);
		mainSprite->runAction(moveEvent);
	}
	if (intDirUp != 0)
	{
		auto moveEvent = MoveBy::create(0.0f, Vec2(0.0f, 50.f) * intDirUp * delta);
		mainSprite->runAction(moveEvent);
	}

	//GLProgramState* state = GLProgramState::getOrCreateWithGLProgram(CharEffect);
	//mainSprite->setGLProgram(CharEffect);
	//mainSprite->setGLProgramState(state);
	//state->setUniformVec2("loc", mLoc);

	GLProgramState* state = GLProgramState::getOrCreateWithGLProgram(CharEffect);
	mainSprite->setGLProgram(CharEffect);
	mainSprite->setGLProgramState(state);
	state->setUniformVec2("loc", mLoc);
}