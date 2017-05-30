#include "HelloWorldScene2.h"
#include "SimpleAudioEngine.h"

#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld2::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelloWorld2::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld2::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size playingSize = Size(visibleSize.width, visibleSize.height - (visibleSize.height / 8));

	if (!CCLayerColor::initWithColor(ccc4(255, 255, 255, 255))) //RGBA
	{
		return false;
	}

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	//auto closeItem = MenuItemImage::create(
	//                                       "CloseNormal.png",
	//                                       "CloseSelected.png",
	//                                       CC_CALLBACK_1(HelloWorld2::menuCloseCallback, this));

	//closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
	//                            origin.y + closeItem->getContentSize().height/2));

	// create menu, it's an autorelease object
	//auto menu = Menu::create(closeItem, NULL);
	//menu->setPosition(Vec2::ZERO);
	//this->addChild(menu, 1);

	/////////////////////////////

	//mainChar.mLoc.set(.5f, .5f);
	//mainChar.mLocInc.set(.005f, .01f);
	//
	//auto shaderCharEffect = new GLProgram();
	//shaderCharEffect->initWithFilenames("Basic.vsh", "CharEffect.fsh");
	//shaderCharEffect->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
	//shaderCharEffect->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_COLOR);
	//shaderCharEffect->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
	//shaderCharEffect->link();
	//shaderCharEffect->updateUniforms();
	//
	//GLProgramState* state = GLProgramState::getOrCreateWithGLProgram(shaderCharEffect);
	//mainChar.getSprite()->setGLProgram(shaderCharEffect);
	//mainChar.getSprite()->setGLProgramState(state);
	//state->setUniformVec2("loc", mainChar.mLoc);

	//proPostProcess = GLProgram::createWithFilenames("Basic.vsh", "GreyScale.fsh");
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_COLOR, GLProgram::VERTEX_ATTRIB_POSITION);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_COLOR);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORD);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD1, GLProgram::VERTEX_ATTRIB_TEX_COORD1);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD2, GLProgram::VERTEX_ATTRIB_TEX_COORD2);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD3, GLProgram::VERTEX_ATTRIB_TEX_COORD3);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_NORMAL, GLProgram::VERTEX_ATTRIB_NORMAL);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_BLEND_WEIGHT, GLProgram::VERTEX_ATTRIB_BLEND_WEIGHT);
	//proPostProcess->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_BLEND_INDEX, GLProgram::VERTEX_ATTRIB_BLEND_INDEX);
	//proPostProcess->link();
	//proPostProcess->updateUniforms();
	//
	//rendtex = RenderTexture::create(visibleSize.width, visibleSize.height);
	//rendtex->retain();
	//
	//rendtexSprite = Sprite::createWithTexture(rendtex->getSprite()->getTexture());
	//rendtexSprite->setTextureRect(Rect(0, 0, rendtexSprite->getTexture()->getContentSize().width, rendtexSprite->getTexture()->getContentSize().height));
	//rendtexSprite->setAnchorPoint(Point::ZERO);
	//rendtexSprite->setPosition(Point::ZERO);
	//rendtexSprite->setFlippedY(true);
	//rendtexSprite->setGLProgram(proPostProcess);
	//this->addChild(rendtexSprite, 2);

	// 3. add your codes below...

	auto nodeItems = Node::create();
	nodeItems->setName("nodeItems");
	//nodeItems->setPosition(50, 50);

	auto sprite = Sprite::create("wall_1.png");
	int sX = 0;
	int sY = playingSize.height / 2;

	int howMany = std::ceil(visibleSize.width / sprite->getContentSize().width);

	for (int i = 0; i < howMany; i++)
	{
		auto sprite = Sprite::create("wall_1.png");
		sprite->setAnchorPoint(Vec2::ZERO);
		sprite->setPosition(sX, sY);
		sX += sprite->getContentSize().width;

		nodeItems->addChild(sprite, 0);
	}

	this->addChild(nodeItems, 1);

	//

	auto spriteNode = Node::create();
	spriteNode->setName("spriteNode");

	//auto mainSprite = Sprite::create("Blue_Front1.png");
	//mainSprite->setAnchorPoint(Vec2(0, 0));
	//mainSprite->setPosition(100, (visibleSize.height / 2));
	//mainSprite->setName("mainSprite");
	//
	//spriteNode->addChild(mainSprite, 1);
	//this->addChild(spriteNode, 1);

	mainChar.init("Blue_Front1.png", "mainSprite", 100, (visibleSize.height / 2));
	spriteNode->addChild(mainChar.getSprite(), 1);
	this->addChild(spriteNode, 1);

	//auto moveEvent = MoveBy::create(5, Vec2(200, 0));
	////mainSprite->runAction(moveEvent);
	//
	//auto delay = DelayTime::create(5.0f);
	//auto delaySequence = Sequence::create(delay, delay->clone(), nullptr);
	//auto sequence = Sequence::create(moveEvent, moveEvent->reverse(), delaySequence, nullptr);
	//mainSprite->runAction(sequence);
	//mainSprite->runAction(sequence->reverse());

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(HelloWorld2::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(HelloWorld2::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	auto mouseListener = EventListenerMouse::create();
	mouseListener->onMouseDown = CC_CALLBACK_1(HelloWorld2::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

	// add a label shows "Hello World"
	// create and initialize a label

	//auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);

	// position the label on the center of the screen
	//label->setPosition(Vec2(origin.x + visibleSize.width/2,
	//                        origin.y + visibleSize.height - label->getContentSize().height));

	// add the label as a child to this layer
	//this->addChild(label, 1);

	// add "HelloWorld2" splash screen"
	//auto sprite = Sprite::create("HelloWorld2.png");

	// position the sprite on the center of the screen
	//sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	//this->addChild(sprite, 0);

	this->scheduleUpdate();

	return true;
}

void HelloWorld2::update(float delta)
{
	auto cam = Camera::getDefaultCamera();
	//cam->setPosition(mainChar.getPos());

	mainChar.Update(delta);

	//rendtex->beginWithClear(.0f, .0f, .0f, .0f);
	//this->visit();
	//rendtex->end();
	//rendtexSprite->setTexture(rendtex->getSprite()->getTexture());
	//rendtexSprite->setGLProgram(proPostProcess);

	//Camera* cam = Camera::getDefaultCamera();
	//cam->setPosition(mainChar.getSprite()->getPosition());
	//
	//rendtex->beginWithClear(.0f, .0f, .0f, .0f);
}

void HelloWorld2::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
	{
		mainChar.MoveChar(1, 0);
		auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");
		//auto moveEvent = MoveBy::create(0.5f, Vec2(50.0f, 0.f));
		//curSprite->runAction(moveEvent);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
	{
		mainChar.MoveChar(-1, 0);
		auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");
		//auto moveEvent = MoveBy::create(0.5f, Vec2(-50.0f, 0.f));
		//curSprite->runAction(moveEvent);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
	{
		mainChar.MoveChar(0, 1);
		auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");
		//auto moveEvent = MoveBy::create(0.5f, Vec2(-50.0f, 0.f));
		//curSprite->runAction(moveEvent);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
	{
		mainChar.MoveChar(0, -1);
		auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");
		//auto moveEvent = MoveBy::create(0.5f, Vec2(-50.0f, 0.f));
		//curSprite->runAction(moveEvent);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		CCDirector::getInstance()->replaceScene(TransitionFade::create(1.5, HelloWorld::createScene(), Color3B(0, 255, 255)));
	}
}

void HelloWorld2::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)

{

	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)

	{

		/*auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");

		auto moveEvent = MoveBy::create(0.5f, Vec2(50.0f, 0.f));

		curSprite->runAction(moveEvent);*/
		mainChar.MoveChar(-1, 0);

		mainChar.Stop(1);

	}

	else if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)

	{

		/*auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");

		auto moveEvent = MoveBy::create(0.5f, Vec2(-50.0f, 0.f));

		curSprite->runAction(moveEvent);*/

		mainChar.MoveChar(1, 0);


		mainChar.Stop(1);

	}


	else if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)

	{

		mainChar.MoveChar(0, -1);

		mainChar.Stop(0);

	}

	else if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)

	{

		mainChar.MoveChar(0, 1);

		mainChar.Stop(0);

	}
}

void HelloWorld2::onMouseDown(EventMouse* eventM)
{
	//auto curSprite = this->getChildByName("spriteNode")->getChildByName("mainSprite");
	//curSprite->stopAllActions();
	//auto moveEvent = MoveTo::create(0.5f, Vec2(eventM->getCursorX(), eventM->getCursorY()));
	//curSprite->runAction(moveEvent);
	mainChar.MoveCharByCoord(eventM->getCursorX(), eventM->getCursorY());
}

void HelloWorld2::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

GameChar* HelloWorld2::getChar()
{
	return &mainChar;
}