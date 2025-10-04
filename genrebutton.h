#pragma once
#include "button.h"
#include <string>
#include <list>
class genrebutton : public button
{

public:
	void draw(int n);
	void update(int n);  
	std::string genres[6] = { "mermaids", "fairies", "princesses", "classics", "modern", "christmas" };
	std::string findGenre(float x, float y);
	bool contains(float x, float y, float cx, float cy, float width, float height);
	std::string getGenre(int i) { return genres[i]; }
};