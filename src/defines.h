#pragma once
#include  <math.h>
#include <string>
using namespace std;

#define ASSET_PATH ".\\assets\\"
#define movie_height 5.7f
#define movie_width 4.0f
#define slider_width 6.0f
#define slider_height 3.6f
#define SearchBar_X 14.f
#define SearchBar_Y 1.0f
#define Slider_X 24.5f
#define Slider_Y 2.1f
#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 16.0f

#define SETCOLOR(c, r, g, b) {c[0]=r; c[1]=g; c[2]=b;}; 

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}