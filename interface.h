#pragma once
#include "moviebutton.h"
#include "slider.h"
#include "genrebutton.h"
#include <list>
#include "arrowbutton.h"
#include "returnbutton.h"
class Interface
{
public:
	enum state { STATE_INIT, STATE_LOADING, STATE_IDLE, STATE_MOVING , STATE_SLIDER, STATE_GENRE};
protected:
	static Interface* m_instance;

	Interface() {}
	moviebutton* m_active_movie = nullptr;
	slider* m_active_slider = nullptr;
	genrebutton* m_active_genre = nullptr;
	state m_state = STATE_INIT;

public:
	void draw();
	void update();
	void init();

	std::list<moviebutton*> m_movies;
	std::list<genrebutton*> m_genres;
	slider* sl = new slider;
	arrowbutton* arrow = new arrowbutton;
	returnbutton* rb = new returnbutton;
	genrebutton* gen = new genrebutton;
	std::string genr;


	~Interface();
	static void releaseInstance() { if (m_instance) delete m_instance; m_instance = nullptr; }
	static Interface* getInstance();

};
