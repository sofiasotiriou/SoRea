#pragma once
#include "button.h"

class returnbutton : public button
{
public:
	void draw();
	bool contains(float x, float y, float cx, float cy, float width, float height);
	//bool contains(float x, float y);
};