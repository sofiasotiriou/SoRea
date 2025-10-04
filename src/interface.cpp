#include "defines.h"
#include "interface.h"
#include "sgg/graphics.h"
#include"slider.h"
#include "moviebutton.h"
#include "returnbutton.h"

void Interface::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;

	// the UI is still loading
	if (m_state == STATE_INIT)
	{
		graphics::setFont("Des.ttf");
		SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
		graphics::drawText(10.0f, CANVAS_HEIGHT / 2, 2.0f, "Loading...", br);
		m_state = STATE_LOADING;
		return;
	}

	// draws the background
	SETCOLOR(br.fill_color, 0.98f, 0.804f, 0.898f);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
	graphics::drawRect(17.0f, 10.0f, 0.2f, 20.0f, br);

	sl->draw();
	int pagenum = arrow->getPage();
	int i = 0;
	for (auto gen : m_genres) {
		gen->draw(i);
		i++;
	}

	// when the slider is active
	if (m_state == STATE_SLIDER) {
		moviebutton* tempmovie = new moviebutton;
		float y = 5.0f;
		float x = 3.0f;
		std::list<int> movies = tempmovie->movieYear(sl->findYear());	// finds the movies of the selected year and stores them in a list
		delete tempmovie;
		for (int i = 0; i < 6; i++) {
			if (movies.empty()) {
				break;
			}
			graphics::drawText(0.6f, 1.2f, 0.8f, "Barbie movies produced in " + to_string(sl->findYear()), br);
			moviebutton* movie = new moviebutton;	// creates new object for each movie and sets its position and number
			movie->setPosX(x);
			movie->setPosY(y);
			movie->setNum(movies.front());
			m_movies.push_back(movie);
			if (x < 14.0f) {
				x += 5.5f;		// "step" for axis x
			}
			else if (y < 11.f) {
				y += 7.5f;		// "step" for axis y
				x = 3.0f;
			}
			movies.pop_front();
		}
		rb->draw();
		
	}
	// when one of the genre buttons is active
	else if (m_state == STATE_GENRE) {
		moviebutton* tempmovie = new moviebutton;
		std::list<int> movies = tempmovie->movieGenre(genr);
		delete tempmovie;
		float y = 5.0f;
		float x = 3.0f;
		for (int i = 0; i < 6; i++) {
			if (movies.empty()) {
				break;
			}
			graphics::drawText(0.6f, 1.2f, 0.8f, genr, br);
			moviebutton* movie = new moviebutton;		// creates new object for each movie and sets its position and number
			movie->setPosX(x);
			movie->setPosY(y);
			movie->setNum(movies.front());
			m_movies.push_back(movie);
			if (x < 14.0f) {
				x += 5.5f;		// "step" for axis x
			}
			else if (y < 11.f) {
				y += 7.5f;		// "step" for axis y
				x = 3.0f;
			}
			movies.pop_front();
		}
		rb->draw();
	}
	// this is the original state of the UI
	else if (m_state == STATE_IDLE){
		std::string genre1;
		std::string genre2;

		graphics::setFont("Des.ttf");
		// accordingly to the page number, it finds what info should be shown
		if (pagenum == 1) {
			genre1 = "mermaids";
			genre2 = "fairies";
		}
		else if (pagenum == 2) {
			genre1 = "princesses";
			genre2 = "reimagined classics";
			pagenum = 7;
			
		}
		else if (pagenum == 3) {
			genre1 = "modern day";
			genre2 = "christmas joy";
			pagenum = 13;
		}
		SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
		graphics::drawText(1.f, 1.6f, 0.7f, genre1, br);
		graphics::drawText(1.f, 9.0f, 0.7, genre2, br);
		arrow->draw();
	}
	// when the slider is still moving 
	else if (m_state == STATE_MOVING) {
		SETCOLOR(br.fill_color, 0.98f, 0.804f, 0.898f);
		graphics::drawRect(CANVAS_WIDTH / 3, CANVAS_HEIGHT / 3, CANVAS_WIDTH/2, CANVAS_HEIGHT/2, br);
		br.outline_opacity = 1.f;
		SETCOLOR(br.fill_color, 0.945f, 0.553f, 0.737f);
		graphics::drawRect(sl->getPosX(), sl->getPosY() + 0.5, 1.f, 0.4f, br);
		SETCOLOR(br.fill_color, 0.878f, 0.129f, 0.541f);
		graphics::drawText(sl->getPosX() - 0.45, sl->getPosY() + 0.65, 0.4f, to_string(sl->findYear()), br);
		return;
	}
	// draws each movie
	for (auto movie : m_movies)
	{
		int movienum = movie->getNum();
		if (m_state == STATE_IDLE) {
			movienum += pagenum;
		}
		movie->draw(movienum);
	}
}

void Interface::update()
{
	graphics::Brush br;
	if (m_state == STATE_INIT)
	{
		return;
	}
	if (m_state == STATE_LOADING)
	{
		init();
		m_state = STATE_IDLE;
		return;
	}
	sl->update();
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);
	moviebutton* cur_movie = nullptr;
	for (auto movie : m_movies) {
		if (movie != m_active_movie) {
			movie->setActive(false);
		}
		if (movie->contains(mx, my, movie->getPosX(), movie->getPosY(), movie_width, movie_height)) {		// if the mouse hovers over a movie, highlight it
			movie->setHighlight(true);
			cur_movie = movie;
		}
		else
			movie->setHighlight(false);
	}
	genrebutton* cur_genre = nullptr;
	for (auto gnr : m_genres) {
		if (gnr != m_active_genre) {
			gnr->setActive(false);
		}
		if (gnr->contains(mx, my, gnr->getPosX(), gnr->getPosY(), 2.7f, 1.0f)) {		// if the mouse hovers over a genre button, highlight it
			cur_genre = gnr;
			gnr->setHighlight(true);
		}
		else
			gnr->setHighlight(false);
	}
	slider* cur_sl = nullptr;

	// if the mouse hovers over the return button and the left mouse button is pressed 
	// go back to the original state of the UI
	if (rb->contains(mx, my, 14.0f, 14.5f, 5.0f, 1.2f) && ms.button_left_pressed) {
		init();
		m_state = STATE_IDLE;		
		sl->setX(22.f);		// resets the slider
		arrow->setPage(1);
		return;
	}

	// if the mouse hovers over the right arrow button and the left mouse button is pressed 
	// show the movies of the next page
	if (arrow->next(mx, my) && ms.button_left_pressed) {
		arrow->setPage(arrow->getPage() + 1);
		int c = (arrow->getPage()) * 6 - 5;
		for (auto movie : m_movies) {
			movie->draw(c);
			c++;
		}
		if (m_active_movie) {
			m_active_movie->setActive(false);
		}
	}
	// if the mouse hovers over the left arrow button and the left mouse button is pressed 
	// show the movies of the prenious page
	if (arrow->previous(mx, my) && ms.button_left_pressed) {
		arrow->setPage(arrow->getPage() - 1);
		int c = 1;
		if (arrow->getPage() == 2) {
			c = 2;
		}
		for (auto movie : m_movies) {
			movie->draw(c);
			c++;
		}
		if (m_active_movie) {
			m_active_movie->setActive(false);
		}
	}

	if (sl->contains(mx, my)) {
		sl->setHighlight(true);
		cur_sl = sl;
	}

	if (ms.button_left_pressed && cur_movie) {
		m_active_movie = cur_movie;
		m_active_movie->setActive(true);
	}
	else if (ms.button_left_pressed && cur_sl)
	{
		m_active_slider = cur_sl;
		m_active_slider->setActive(true);
	}
	else if (ms.button_left_pressed && cur_genre) {
		sl->setX(22.0f);
		m_active_genre = cur_genre;
		m_active_genre->setActive(true);
		m_state = STATE_GENRE;
		int i = 0;
		for (auto genre : m_genres) {
			if (genre == m_active_genre) {	// finds and stores what genre was selected
				genr = genre->getGenre(i);
				break;
			}
			i++;
		}
		if (genr == "classics") {
			genr = "reimagined classics";
		}
		else if (genr == "modern") {
			genr = "modern day";
		}
		else if (genr == "christmas") {
			genr = "christmas joy";
		}
		if (m_active_movie) {
			m_active_movie->setActive(false);
		}
		m_movies.clear();
	}
	if (sl != m_active_slider) {
		sl->setActive(false);
	}

	// slider dragging 
	if (ms.dragging && m_active_slider)
	{
		m_state = STATE_MOVING;
		m_active_slider->setX(mx);
	}

	if (ms.button_left_released && m_active_slider)
	{
		m_state = STATE_SLIDER;
		if (m_active_movie) {
			m_active_movie->setActive(false);
		}
		if (m_active_genre) {
			m_active_genre->setActive(false);
		}
		m_movies.clear();
		m_active_slider->setActive(false);
		m_active_slider = nullptr;
	}

}

void Interface::init()
{
	m_movies.clear();
	m_genres.clear();
	float y = 5.0f;
	float x = 3.0f;

	int n = 0;
	for (int i = 0; i < 6; i++)		// creates the layout of the movies
	{
		moviebutton* movie = new moviebutton();
		m_movies.push_back(movie);

		movie->setPosX(x);
		movie->setPosY(y);
		movie->setNum(n);
		n++;
		if (x < 14.0f) {
			x += 5.5f;
		}
		else if (y < 11.f) {
			y += 7.5f;
			x = 3.0f;
		}
	}
	x = 19.2f;
	y = 1.0f;

	for (int i = 0; i < 6; i++)		// creates the layout for the genre buttons
	{
		genrebutton* gen = new genrebutton();
		m_genres.push_back(gen);
		gen->setPosX(x);
		gen->setPosY(y);
		if (i < 3) {
			y += 1.4f;
		}
		else {
			x += 3.4f;
		}
	}
	graphics::preloadBitmaps(ASSET_PATH);
}

Interface::~Interface()
{
	for (auto movie : m_movies)
	{
		delete movie;
	}
	m_movies.clear();

	for (auto genre : m_genres)
	{
		delete genre;
	}
	m_genres.clear();
	delete sl;
	delete arrow;
	delete rb;
	delete gen;
	delete m_active_movie;
	delete m_active_slider;
	delete m_active_genre;
}

Interface* Interface::getInstance()
{
	if (!m_instance)
		m_instance = new Interface();
	return m_instance;
}

Interface* Interface::m_instance = nullptr;