#pragma once
#include <defines.h>
#include <iostream>
#include <fstream>
#include <TextureLoader.h>
#include <random>
class Card
{
public:
	Card();
	~Card();

	
	void init(std::string configFile);
	void reset();
	void destroy();
	void draw();
	void changeTextureBack();
	void changeTextureFront();
	int getCardID();
	void setCardID(int setID);
	void hide();
	void show();
	int ID;
	bool isVisible = true;
	drawable card;
	SDL_Rect dstRect = { 0, 0, 0, 0 };
	int random = 0;
	SDL_Texture* front;
	SDL_Texture* back;
	SDL_Rect drawRect;
	static TextureLoader textureLoaderCard;
	bool selected = false;

private:




	


};

