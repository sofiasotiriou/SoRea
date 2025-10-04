#include "moviebutton.h"
#include "sgg/graphics.h"
#include "defines.h"
#include <string>

//draws a movie 
void moviebutton::draw(int num)
{
	graphics::Brush br;
	br.outline_opacity = 1.f * m_active;
	if (m_highlighted) {		// draws a outline around the movies
		SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
		graphics::drawRect(getPosX(), getPosY(), movie_width + 0.1f, movie_height + 0.1f, br);
	}
	if (m_active) { //if a movie is selected draw the movie's information
		update(num);
	}
	br.outline_opacity = 0.f;
	SETCOLOR(br.fill_color, 1.f, 1.f, 1.f);
	string name = "image" + to_string(num) + ".png";
	br.texture = ASSET_PATH + std::string(name);
	graphics::drawRect(getPosX(), getPosY(), movie_width, movie_height, br);
}


std::list<int> moviebutton::movieYear(int year) { //counts how many movies were produced in the year the slider is currently in and keeps the array pointer of each movie
	std::list<int> count;
	for (int i = 0; i < 18; i++) {
		if (prodYears[i] == year) {
			count.push_back(i + 1);
		}
	}
	if (count.empty()) {		//if no movies were created, a message is drawn
		graphics::Brush br;
		br.outline_opacity = 0;
		SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
		graphics::drawRect(8.2f, 7.2f, 10.2f, 4.7f, br);
		SETCOLOR(br.fill_color, 0.945f, 0.553f, 0.737f);
		graphics::drawRect(8.2f, 7.2f, 10.f, 4.5f, br);
		SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
		graphics::drawText(3.8f, 6.8f, 1.f, "No barbie movies from", br);
		graphics::drawText(4.5f, 8.f, 1.f, to_string(year)+" were found." , br);
	}
	return count;
}

std::list<int> moviebutton::movieGenre(std::string gen) {		//Keeps the array pointer of each movie in the chosen genre
	std::list<int> count;
	for (int i = 0; i < 18; i++) {
		if (genre[i] == gen) {
			count.push_back(i + 1);
		}
	}

	return count;
}

//draws the information of the movie the user clicked on 
void moviebutton::update(int i)			
{
	graphics::Brush br;
	graphics::setFont("Des.ttf");
	std::string title = movieNames[i - 1] + "   (" + to_string(prodYears[i - 1]) + ")";
	SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
	graphics::drawRect(22.55f, 10.8f, 10.5f, 9.3f, br);
	SETCOLOR(br.fill_color, 0.98f, 0.804f, 0.898f);
	graphics::drawText(17.6f, 6.8f, 0.6f, title, br);
	float row = 7.6f;
	for (int j = 0; j < 6; j++) {
		graphics::drawText(17.6f, row, 0.5f, descriptions[i - 1][j], br);
		row += 0.6f;
	}
	row += 0.6f;
	graphics::drawText(17.6f, row, 0.5f, "Directed by: " + directors[i - 1], br);
	row += 1.2f;
	graphics::drawText(17.6f, row, 0.5f, "Stars: " + voiceActors[i - 1][0], br);
	row += 0.6f;
	graphics::drawText(17.6f, row, 0.5f, voiceActors[i - 1][1], br);
	row += 1.2f;
	graphics::drawText(17.6f, row, 0.5f, "Genre: " + genre[i - 1], br);

}

//checks whether the mouse clicked withing the border of a certain movie
bool moviebutton::contains(float x, float y, float cx, float cy, float width, float height)				
{
	if (x >= cx - (width/2) && x <= cx + (width/2) && y >= cy - (height/2) && y <= cy + (height/2))
	{
		return true;
	}
	else
	{
		return false;
	}
}



moviebutton::moviebutton()
{
}