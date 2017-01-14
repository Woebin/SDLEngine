#include "Source.h"
#include "GameEngine.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "SpriteSheet.h"
using namespace lazyEngine;


int main(int argc, char** argv) {
	GameEngine ge;
	SDL_Rect rp = { 200,205,38,38 };
	SDL_Rect rb = { 0,0,640,480 };
	SDL_Rect re = { 200,0,64,64 };
	SpriteSheet ps1("img/robojerk.png", 38, 38, 8, 3);
	SpriteSheet ps2("img/robojerkreverse.png", 38, 38, 8, 3);
	Player p(rp, 5, ps1, ps2);
	SpriteSheet en1("img/fireball.png", 64, 64, 8, 8);
	SpriteSheet en2("img/explosion.png", 64, 64, 5, 5);
	Enemy e1(re, 2, en1, en2);
	Background bg(rb, "img/stolenBg.png"); // "Borrowed" from http://www.emunix.emich.edu/~evett/GameProgramming/BookCode/chapter11.new/timedloop/background.bmp
	ge.add(&bg);
	ge.add(&p);
	ge.add(&e1);
	ge.run();

	return 0;
}

Source::Source()
{
}


Source::~Source()
{
}
