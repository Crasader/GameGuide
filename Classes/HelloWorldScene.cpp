#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    
    auto layer = HelloWorld::create();

    scene->addChild(layer);

    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);

	auto button = Button::create("CloseNormal.png","CloseSelected.png");
	button->setPosition(Vec2(100,100));
	addChild(button);

	button->addClickEventListener([](Ref* ref)
	{
		log("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");

	});

	auto button1 = Button::create("CloseNormal.png","CloseSelected.png");
	button1->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,Director::getInstance()->getVisibleSize().height / 2));
	addChild(button1);

	button1->addClickEventListener([](Ref* ref)
	{
		log("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

	});

	auto guide = GuideLayer::create();
	addChild(guide);


    return true;
}
