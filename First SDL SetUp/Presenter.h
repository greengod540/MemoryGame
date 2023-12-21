#pragma once
#include <Engine.h>
#include <defines.h>

class Presenter {
public:
	static SDL_Window* m_mainWindow;

	static SDL_Renderer* m_mainRenderer;

	static int m_SCREEN_WIDTH;
	static int m_SCREEN_HEIGHT;

	void init();
	void Update();
	void Draw();

	
	static void drawObject(drawable& drawable);
	static void drawObject(SDL_Texture* texture);
	static void drawObject(drawDstRect& dstRect);
	static void drawObject(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect);
	static void drawObject(SDL_Texture* texture, SDL_Rect dstRect);
	static int mouseXMultiply;
	static int mouseYMultiply;
	static int mouseX;
	static int mouseY;
private:

	void improveRenderer();

};
template <typename Params>

void drawObject(Params& value) {
	Presenter::drawObject(value);
}
	


