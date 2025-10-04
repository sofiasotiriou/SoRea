#include "genrebutton.h"

//draws a genre button 
void genrebutton::draw(int n)	
{
	graphics::Brush br;
	graphics::setFont("Des.ttf");
	br.outline_opacity = 1.f * m_active;
	if (m_highlighted) {		// draws a outline around the movie when the mouse hovers over it
		SETCOLOR(br.fill_color, 0.945f, 0.553f, 0.737f);
		graphics::drawRect(getPosX(), getPosY(), 2.8f, 1.1f, br);
	}

	SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
	graphics::drawRect(getPosX(), getPosY(), 2.7f, 1.0f, br);
	float posX = 1.0f;

	if (n == 5 || n == 2)			//depending on the parameter give, prints the correct category on the button
	{
		posX = getPosX() - 1.27f;
	}
	else if (n == 0)
	{
		posX = getPosX() - 1.2f;
	}
	else if (n == 1 || n == 3)
	{
		posX = getPosX() - 1.0f;
	}
	else
	{
		posX = getPosX() - 1.0f;
	}

	SETCOLOR(br.fill_color, 0.98f, 0.804f, 0.898f);
	graphics::drawText(posX, getPosY() + 0.2f, 0.6f, genres[n], br);

}

//finds the genre of the button clicked 
std::string genrebutton::findGenre(float x, float y) {		
	int myX = 19.2f;
	int myY = 1.f;
	for (int i = 0; i < 6; i++) {
		if (distance(x, y, myX, myY)<=2.7f*0.7f && distance(x,y,myX,myY)<=0.7f) {
			return genres[i];
		}
		if (i < 3) {
			y += 1.4f;
		}
		else {
			x += 3.4f;
		}
	}
}

//checks whether the mouse clicked withing the border of a certain button
bool genrebutton::contains(float x, float y, float cx, float cy, float width, float height)			
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