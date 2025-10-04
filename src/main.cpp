#include "sgg/graphics.h"
#include "Interface.h"
#include "defines.h"

void draw()
{
	Interface* newinterface = Interface::getInstance();
	newinterface->draw();
}

void update(float ms)
{
	Interface* newinterface = Interface::getInstance();
	newinterface->update();
}


int main(int argc, char** argv)
{
	graphics::createWindow(1200, 800, "SoRea");

	Interface* interface = Interface::getInstance();


	graphics::setUserData(interface);

	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT); 
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop(); 

	Interface::releaseInstance();

	return 0;
}