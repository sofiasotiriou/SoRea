#pragma once
#include "widget.h"

class slider : public widget
{
protected: 
	float pos[2] = { 22.0f,3.1f };
	bool slide;
public: 
	void setX(float x);
	void setSliding(bool s) { slide = s; }
	float getPosX() { return pos[0]; }
	float getPosY() { return pos[1]; }
	void draw();
	void update();
	slider();
	bool contains(float x, float y);
	int findYear();
};