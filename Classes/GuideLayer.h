#ifndef __GUIDELAYER_H__
#define __GUIDELAYER_H__

#include "cocos2d.h"

USING_NS_CC;

class GuideLayer : public cocos2d::Layer
{
public:
	GuideLayer(void);
	~GuideLayer(void);

	static GuideLayer* create();

	bool init();

	bool onTouchBegan(Touch *touch, Event *event);

private:

	void initGuide();

	void setStep(int step);

private:

	Size size;

	ClippingNode* clippingNode;

	Node* stencil;

	bool isFixed;

};

#endif //__GUIDELAYER_H__



