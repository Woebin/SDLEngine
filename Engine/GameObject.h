#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>


namespace lazyEngine {

	class GameObject
	{
	public:
		virtual void draw() = 0;
		virtual ~GameObject();

		// vi v�ljer att INTE l�gga till = 0; f�r om den �r abstrakt s� M�STE alla underklasser definera denna klass
		// med {} , d� kan dom klasserna som �r intresserade �verskugga dessa, exempelvis button
		virtual void mouseDown(const SDL_Event& eve) {}
		virtual void mouseUp(const SDL_Event& eve) {}
		virtual void keyDown(const SDL_Event& eve) {}
		virtual void keyUp(const SDL_Event& eve) {}
		SDL_Rect getRect() const { return rect; }
		virtual void tick() {}



	protected:
		GameObject(const SDL_Rect& r);
		SDL_Texture* getSheet1() const { return spriteSheet1; }
		SDL_Texture* getSheet2() const { return spriteSheet2; }
		// const
		SDL_Rect rect;
		SDL_Texture* spriteSheet1;
		SDL_Texture* spriteSheet2;

	private:

		GameObject(const GameObject&) = delete;
		const GameObject& operator=(const GameObject&) = delete;
	};
}
#endif