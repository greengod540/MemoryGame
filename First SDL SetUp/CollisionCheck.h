#pragma once
#include <string>
#include <fstream>
#include <SDL.h>
#include <filesystem>
class CollisionCheck
{
	
		

public:
	bool colliding(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety);
	bool collidingX(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety);
	bool collidingY(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety);
		
        


	


};

