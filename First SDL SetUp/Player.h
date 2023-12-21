#pragma once
#include <iostream>
#include <InputManager.h>
#include <defines.h>
class Player
{
public:
	drawable player;
	InputManager inpMan;

	void initPlayer(std::string configFile);
	void drawPlayer(std::string configFile);
	void destroyPlayer();
	void movePlayer(SDL_Event& event);
	int speed = 0;
	bool moving = true;



};

