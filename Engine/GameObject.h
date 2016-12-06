#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

namespace engine {
	class GameObject
	{
	public:
		virtual ~GameObject();
		virtual void draw() = 0;
		virtual void mouseDown(const SDL_Event&) {}
		virtual void mouseUp(const SDL_Event&) {}
		virtual void keyDown(const SDL_Event& eve) {}
		virtual void keyUp(const SDL_Event& eve) {}
		SDL_Rect getRect() const { return rect; }
		//Draw();
		//Tick();
	protected:
		GameObject(const SDL_Rect& r);
	private:
		SDL_Rect rect;
		GameObject(const GameObject&) = delete;
		const GameObject& operator = (const GameObject&) = delete;
	};
}

#endif