#pragma once
#include <SDL.h>
#include<iostream>
#include<string>
#include <defines.h>
class Engine
{

public:

	SDL_Texture* LoadTexture(std::string imagePathBMP, SDL_Renderer* renderer);
	bool colliding(drawDstRect objectRect, drawDstRect targetRect, int offsetx, int offsety);

	
};


