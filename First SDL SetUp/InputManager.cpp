#include "InputManager.h"


std::map<std::string, SDL_Scancode> InputManager::actionMapKeyboard;
std::map<std::string, int> InputManager::actionMapMouse;
std::map<std::string, SDL_Scancode> InputManager::mapControlsKeyBoard(const char* inputKey, std::string nameOfAction) {


	actionMapKeyboard[nameOfAction] = SDL_GetScancodeFromName(inputKey); //get scancode from name, assign it to action
	return actionMapKeyboard; //return map







}



std::map<std::string, int> InputManager::mapControlsMouse(std::string name, std::string button) {


	std::transform(button.begin(), button.end(), button.begin(), ::toupper);
	if (button == "LEFT") {
		actionMapMouse[name] = SDL_BUTTON_LEFT;
	}
	if (button == "RIGHT") {
		actionMapMouse[name] = SDL_BUTTON_RIGHT;

	}
	if (button == "MIDDLE") {
		actionMapMouse[name] = SDL_BUTTON_MIDDLE;
	}

	return actionMapMouse;


}




bool InputManager::mouseButtonPressed(SDL_Event& b, int mouseButton) {
	if (b.type == SDL_MOUSEBUTTONDOWN && b.button.button == mouseButton) {

		return true;


	}
	else {
		return false;
	}
}




bool InputManager::keyboardButtonPressed(SDL_Event e, SDL_Scancode scancode) {

	
	if (e.key.keysym.scancode == scancode) {
			return true;
	}
	else {
		return false;
	}
	
}

int InputManager::getXMouseCoordinates(int xMouse) {
	SDL_GetGlobalMouseState(&xMouse, NULL);
	return xMouse;





}

int InputManager::getYMouseCoordinates(int yMouse) {
	SDL_GetGlobalMouseState(NULL, &yMouse);
	return yMouse;





}

bool InputManager::keyboardButtonHeldDown(SDL_Scancode scancode) {
	const Uint8* keyState = SDL_GetKeyboardState(nullptr);
	return keyState[scancode];
}

