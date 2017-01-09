#include "Source.h"
#include "GameEngine.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
using namespace lazyEngine;


int main(int argc, char** argv) {
	GameEngine ge;
	SDL_Rect rp = { 200,200,39,39 };
	SDL_Rect rb = { 0,0,640,480 };
	SDL_Rect re = { 320,0,64,64 };
	Player p(rp, 5);
	Enemy e1(re, 2);
	Background bg(rb);
	ge.add(&bg);
	ge.add(&p);
	ge.add(&e1);
	ge.run();

	//Frame frame;
	/*Label* lab = Label::getInstance({ 250,100,100,100 }, "0");
	frame.add(lab);
	Component* c1 = new MyButton({ 100,100,100,100 }, "Increase", lab);
	frame.add(c1);
	Component* c2 = new MyButton({ 400,100,100,100 }, "Decrease", lab);
	frame.add(c2);*/
	//frame.run();
	return 0;
}

Source::Source()
{
}


Source::~Source()
{
}
