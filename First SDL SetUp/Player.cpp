#include "Player.h"
#include <iostream>
#include <Presenter.h>
#include "TextureLoader.h"
#include "InputManager.h"
#include <SDL.h>
#include "TileAnimation.h"
#include <CollisionCheck.h>

Presenter presenter;
TextureLoader textload;
int2 pos = { 0, 0 };

int speed = 0;




void Player::initPlayer(std::string configFile) {



	std::fstream stream;
	std::string tmp, texture;

	SDL_Rect srcRect, dstRect;

	stream.open(configFile);

	stream >> tmp >> texture;
	stream >> tmp >> srcRect.x >> srcRect.y >> srcRect.w >> srcRect.h;
	stream >> tmp >> dstRect.x >> dstRect.y >> dstRect.w >> dstRect.h;
	
	stream >> tmp >> speed;
	

	stream.close();


	std::cout << dstRect.x << dstRect.y;

	player.texture = textload.CreateTexture(texture, presenter.m_mainRenderer);


	
	player.dstRect = dstRect;
	player.srcRect = srcRect;

	std::cout << texture;
	std::cout << configFile;
	


	

}

void Player::drawPlayer(std::string configFile)
{
	presenter.drawObject(player.texture, player.srcRect, player.dstRect);
	


}

void Player::destroyPlayer()
{
	SDL_DestroyTexture(player.texture);

}

// Player.cpp
// Player.cpp
void Player::movePlayer(SDL_Event& e)
{

	inpMan.mapControlsKeyBoard("W", "forward");
	inpMan.mapControlsKeyBoard("A", "left");
	inpMan.mapControlsKeyBoard("S", "back");
	inpMan.mapControlsKeyBoard("D", "right");
	inpMan.mapControlsKeyBoard("S", "forward2");
	inpMan.mapControlsKeyBoard("D", "left2");
	inpMan.mapControlsKeyBoard("W", "back2");
	inpMan.mapControlsKeyBoard("A", "right2");

	if (inpMan.keyboardButtonHeldDown(SDL_SCANCODE_R)) {
		if (inpMan.keyboardButtonPressed(e, SDL_SCANCODE_W)) {

			player.dstRect.y -= speed;
		}
		else if (inpMan.keyboardButtonPressed(e, SDL_SCANCODE_A)) {
			player.dstRect.x -= speed;
		}
		else if (inpMan.keyboardButtonPressed(e, SDL_SCANCODE_S)) {
			player.dstRect.y += speed;
		}
		else if (inpMan.keyboardButtonPressed(e, SDL_SCANCODE_D)) {
			player.dstRect.x += speed;
		}
	}
	else {

		if (inpMan.keyboardButtonPressed(e, inpMan.actionMapKeyboard["forward2"])) {

			player.dstRect.y -= speed;
		}
		else if (inpMan.keyboardButtonPressed(e, inpMan.actionMapKeyboard["back2"])) {
			player.dstRect.x -= speed;
		}
		else if (inpMan.keyboardButtonPressed(e, inpMan.actionMapKeyboard["right2"])) {
			player.dstRect.y += speed;
		}
		else if (inpMan.keyboardButtonPressed(e, inpMan.actionMapKeyboard["left2"])) {
			player.dstRect.x += speed;
		}

	}

	

	if (player.dstRect.x <= 0) {
		player.dstRect.x += 100;
	}
	else if (player.dstRect.x >= 1920) {
		player.dstRect.x -= 100;
	}

	if (player.dstRect.y <= 0) {
		player.dstRect.y += 100;
	}
	else if (player.dstRect.y >= 1080) {
		player.dstRect.y -= 100;
	}

	

    
}







