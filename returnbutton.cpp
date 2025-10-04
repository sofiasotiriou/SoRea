#include "returnbutton.h"
#include "sgg/graphics.h"

//draws the return button
void returnbutton::draw(){
	graphics::Brush br;
	SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
	graphics::drawRect(14.f, 14.5f, 5.f, 1.2f, br);
	SETCOLOR(br.fill_color, 0.98f, 0.804f, 0.898f);
	graphics::drawText(13.f, 14.7f, 0.7f, "Return", br);
}

//checks if the mouse clicked within the borders of the button
bool returnbutton::contains(float x, float y, float cx, float cy, float width, float height)
{
	if (x >= cx - (width / 2) && x <= cx + (width / 2) && y >= cy - (height / 2) && y <= cy + (height / 2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
