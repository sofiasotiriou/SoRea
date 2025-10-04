#pragma once
#include "defines.h"
#include "sgg/graphics.h"

class widget
{
protected:
	bool m_highlighted = false;
	bool m_active = false;
	char type;


public:
	void draw() {};
	void update() {};

	void setHighlight(bool h) { m_highlighted = h; }
	void setActive(bool a) { m_active = a; }
	
	bool contains(float x, float y) {}

};