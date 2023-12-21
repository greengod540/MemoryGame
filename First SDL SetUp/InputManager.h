#pragma once
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <map>
#include <SDL.h>
#include <algorithm>

class InputManager
{

	

	

public:
	int xMouseCords = 0;
	int yMouseCords = 0;
	static std::map < std::string, SDL_Scancode> actionMapKeyboard;
	static std::map <std::string, int> actionMapMouse;
	
	const Uint8* keys = SDL_GetKeyboardState(NULL);	
	
	static std::map<std::string, SDL_Scancode> mapControlsKeyBoard(const char* inputKey, std::string nameOfAction);

	static std::map<std::string, int> mapControlsMouse(std::string name, std::string button);

	static bool mouseButtonPressed(SDL_Event& b, int mouseButton);

	static bool keyboardButtonPressed(SDL_Event e, SDL_Scancode scancode);
	
	
	static int getXMouseCoordinates(int xMouse);

	static int getYMouseCoordinates(int yMouse);
	bool keyboardButtonHeldDown(SDL_Scancode scancode);


	



};

