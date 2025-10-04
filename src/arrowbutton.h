#pragma once
#include "button.h"

class arrowbutton : public button
{
	int page = 1;
public:
	void draw();
	void setPage(int pg);
	int getPage();
	bool next(float x, float y);
	bool previous(float x, float y);
};