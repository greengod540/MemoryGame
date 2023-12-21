#include <Presenter.h>
#include <SDL.h>

SDL_Window* Presenter::m_mainWindow = nullptr;
SDL_Renderer* Presenter::m_mainRenderer = nullptr;
int Presenter::m_SCREEN_HEIGHT = 0;
int Presenter::m_SCREEN_WIDTH = 0;

void Presenter::init()
{
	m_SCREEN_WIDTH = 1539;
	m_SCREEN_HEIGHT = 864;

	SDL_Init(SDL_INIT_EVERYTHING);

	m_mainWindow = SDL_CreateWindow("SDL_Template",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, 0);


	m_mainRenderer = SDL_CreateRenderer(m_mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	improveRenderer();

}

void Presenter::Update()
{

}

void Presenter::Draw()
{
	SDL_RenderPresent(m_mainRenderer);


	SDL_RenderClear(m_mainRenderer);
}

void Presenter::drawObject(drawable& drawable)
{
	SDL_RenderCopy(m_mainRenderer, drawable.texture, &drawable.srcRect, NULL);
}

void Presenter::improveRenderer()
{
	

	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);

	auto desktopWidth = DM.w;
	auto desktopHeight = DM.h;

	mouseXMultiply = m_SCREEN_WIDTH / desktopWidth;
	mouseYMultiply = m_SCREEN_HEIGHT / desktopHeight;


	if (SDL_SetWindowFullscreen(m_mainWindow, SDL_WINDOW_FULLSCREEN_DESKTOP) < 0)
	{
		std::cout << "sdl renderer improved failed" << SDL_GetError();

	}

	SDL_RenderSetLogicalSize(m_mainRenderer, m_SCREEN_WIDTH, m_SCREEN_HEIGHT);

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");





	
}

void Presenter::drawObject(drawDstRect& dstRect)
{
	
	SDL_RenderCopy(m_mainRenderer, dstRect.texture, &dstRect.srcRect, &dstRect.dstRect);

}

void Presenter::drawObject(SDL_Texture* texture)
{	
	
	SDL_RenderCopy(m_mainRenderer, texture, NULL, NULL);
}


void Presenter::drawObject(SDL_Texture* texture, SDL_Rect srcRect, SDL_Rect dstRect)
{
	SDL_RenderCopy(m_mainRenderer, texture, &srcRect, &dstRect);
	
}

void Presenter::drawObject(SDL_Texture* texture, SDL_Rect dstRect) {
	SDL_RenderCopy(m_mainRenderer, texture, NULL, &dstRect);
}