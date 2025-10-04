#include "slider.h"

//draws the slider
void slider::draw()			
{
	graphics::Brush br;
	br.outline_opacity = 1.0f * m_highlighted;
	br.outline_width = 0.2f;
	br.outline_opacity = 1.0f *slide;
	SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
	graphics::drawRect(Slider_X, Slider_Y, slider_width, slider_height, br);
	SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
	graphics::drawRect(Slider_X, 3.1f, 5.2f, 0.2f, br);
	SETCOLOR(br.fill_color, 0.945f, 0.553f, 0.737f);
	graphics::drawRect(getPosX(), getPosY(), 0.3f, 0.4f, br);
	SETCOLOR(br.fill_color, 0.98f, 0.804f, 0.898f);
	graphics::drawText(22.4f, 1.4f, 0.75f, "Select a Year", br);
	graphics::setFont("Des.ttf");
	graphics::drawText(21.6f, 2.6f, 0.5f, "2001", br); 
	graphics::drawText(26.2f, 2.6f, 0.5f, "2014", br); 
	SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
}

void slider::update()
{

}

//checks whether the mouse clicked withing the border of the button that gets dragged
bool slider::contains(float x, float y)			
{
	return distance(x, y, getPosX(), 3.1f) <= 0.3f && distance(x, y, getPosX(), 3.1f) <= 0.4f;
}

slider::slider()
{

}

//sets the x value of the slider
void slider::setX(float x) {		
	if (x >= 27.1 || x <= 21.9) return;
	pos[0] = x;
}

// finds the year the slider is on
int slider::findYear() {			
	float x = getPosX();
	int year = 2001;
	for (float i = 21.9; i < 26.6; i += 0.365f) {
		if (distance(i,getPosY(),x,getPosY())<0.365) {
			return year;
		}
		year++;
	}
}