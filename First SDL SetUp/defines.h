#pragma once
#include <iostream>
#include <SDL.h>
#include <string>
#include <fstream>

static std::string imagePath = "img\\";
static std::string configPath = "config\\";
static std::string soundPath = "sound\\";
static std::string cardPath = "card\\";


struct int2 {
	int x;
	int y;
	void reset() {
		x = 0;
		y = 0;
	}
	void set(int a, int b) {
		x = a;
		y = b;
	}

	template <typename params>
	void operator *= (params value) {
		x *= value;
		y *= value;

	}
	template <typename params>
	void operator /=(params value) {
		x /= value;
		y /= value;
	}
	template <typename params>
	int2 operator*(params value) {
		x *= value;
		y *= value;
		return *this; //returns instance of class 
	}

	template <typename params>
	int2 operator/(params value) {
		x /= value;
		y /= value;
		return *this; //returns instance of class 
	}
	template <typename params>
	bool operator!=(params value) {
		if (x != value || y != value) {
			return true;
		}
		else {
			return false;
		}
	}
};

struct drawable {
	SDL_Texture* texture;
	SDL_Rect srcRect; //srcRect;
	SDL_Rect dstRect;
};

struct drawDstRect : drawable {
	SDL_Rect dstRect;
};

enum SOUND 
{

	BACKGROUND_MUSIC,
	PLAYER_COLLISION,
	CARDS_SAME,
	CARDS_NOT_SAME,
	SUCCESS


};
