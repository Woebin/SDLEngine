#include "Source.h"
#include "GameEngine.h"
#include "GameEngine.h"
#include <iostream>
#include <SDL.h>
#include "Frame.h"
#include "GameObject.h"
#include "MobileObject.h"
#include "ImmobileObject.h"

using namespace std;
using namespace engine;

int main(int argc, char** argv) {
	Frame frame;
	/*Label* lab = Label::getInstance({ 250,100,100,100 }, "0");
	frame.add(lab);
	Component* c1 = new MyButton({ 100,100,100,100 }, "Increase", lab);
	frame.add(c1);
	Component* c2 = new MyButton({ 400,100,100,100 }, "Decrease", lab);
	frame.add(c2);*/
	frame.run();
	return 0;
}
