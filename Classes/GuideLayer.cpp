#include "GuideLayer.h"

GuideLayer::GuideLayer(void)
{
	stencil = nullptr;
	isFixed = true;
}

GuideLayer::~GuideLayer(void)
{

}

GuideLayer* GuideLayer::create()
{
	GuideLayer* guide = new GuideLayer();
	if (guide && guide->init())
	{
		guide->autorelease();
		return guide;
	}

	CC_SAFE_DELETE(guide);

	return nullptr;
}

bool GuideLayer::init()
{
	if (!Layer::init()) return false;

	size = Director::getInstance()->getVisibleSize();


	initGuide();

	return true;
}

void GuideLayer::initGuide()
{
	//遮罩
	auto mask = LayerColor::create(Color4B(255,255,255,200));

	//new clippingNode
	clippingNode = ClippingNode::create();
	addChild(clippingNode);

	//clipping config
	clippingNode->addChild(mask);
	clippingNode->setInverted(true);
	clippingNode->setAlphaThreshold(1.0f);
	
	//step
	setStep(1);

	//touch
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);// true:不向下传递  false:向下传递
	listener->onTouchBegan = CC_CALLBACK_2(GuideLayer::onTouchBegan,this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);
}

void GuideLayer::setStep(int step)
{
	Node* stencil = nullptr;

	stencil = Sprite::create("button_1_down.png");
	stencil->setPosition(size.width / 2,size.height / 2);

	clippingNode->setStencil(stencil);
}

bool GuideLayer::onTouchBegan(Touch *touch, Event *event)
{
	if (isFixed)
	{
		auto stencil = clippingNode->getStencil();

		auto rect = stencil->boundingBox();

		auto point = touch->getLocation();

		if (rect.containsPoint(point))
		{
			this->removeFromParent();
			return false;
		}
	}
	else
	{
		this->removeFromParent();
		return false;
	}

	return true;
}