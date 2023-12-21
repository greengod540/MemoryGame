#include "Board.h"
#include<Engine.h>
#include "Presenter.h"
Engine engine;
Presenter presenter1;
#include <Presenter.h>
#include <TileAnimation.h>
#include <InputManager.h>
#include <Player.h>
#include <CollisionCheck.h>
#include <SoundManager.h>
#include <iostream>
#include <fstream>
#include <Card.h>
#include <SDL.h>
#include <vector>
#include <defines.h>
#include <thread>
#include <chrono>
#include <fstream>

bool start = true;
static bool allowed = true;
static const double showCardsDuration = 4.0;
std::map<int, int> ids;


int Presenter::mouseXMultiply;
int Presenter::mouseYMultiply;

bool change_tex = false;
SDL_Texture* background1;

CollisionCheck colCheck;
SoundManager soundManager;

bool draw1 = false;
bool reset = false;



int mousePressed = 0;
std::vector<int> index = { 0, 0 };
TextureLoader textureLoaderBoard;
SDL_Rect mouse_coors;
static bool tryAgainDrawn = false;

Player player1;
Player player2;



int j = 0;

InputManager inpMan;

int xMouse = 0;
int yMouse = 0;
SDL_Texture* tryAgainScreen = nullptr;
SDL_Texture* Yes = nullptr;
SDL_Texture* No = nullptr;
SDL_Texture* tryAgainTexture = engine.LoadTexture("img\\tryagain3.bmp", presenter1.m_mainRenderer);
SDL_Rect tryAgainRect = { 0, 0, 1920, 1080 };
SDL_Texture* Knife = nullptr;
SDL_Texture* Beer1 = nullptr;


Board::Board()
{

}

Board::~Board()
{

}
void Board::mainMenu()
{
}
void Board::setRandomPositions()
{
	for (int p = 0; p < cards.size(); p++) {
		int randomPosX = std::rand() % 1400;
		int randomPosY = std::rand() % 700;
		cards[p].drawRect = {randomPosX, randomPosY, cards[p].dstRect.w, cards[p].dstRect.h};

	}
	
	
	
}
void Board::tryAgain()
{
	soundManager.playSound(SUCCESS);
	presenter1.drawObject(tryAgainScreen, {-100, -100, 1920, 1080});
	presenter1.drawObject(Yes, { 700, 500, 200, 200 });
	presenter1.drawObject(No, { 700, 700, 200, 200 });
	
}

void Board::init()
{
	
	std::string configFile = "config\\boardInit.txt";

	std::fstream stream;

	std::string backgorundImg, playerConfigFile, tmp;


	stream.open(configFile);
	

	stream >> tmp >> backgorundImg;


	stream.close();

	


	

	card1.init("config\\card\\cardInit.txt");
	std::cout << SDL_GetError();
	card2.init("config\\card\\cardInit2.txt");
	card3.init("config\\card\\cardInit3.txt");
	card4.init("config\\card\\cardInit4.txt");
	card5.init("config\\card\\cardInit5.txt");
	card6.init("config\\card\\cardInit6.txt");
	card7.init("config\\card\\cardInit7.txt");
	card8.init("config\\card\\cardInit8.txt");
	card9.init("config\\card\\cardInit9.txt");
	card10.init("config\\card\\cardInit10.txt");
	soundManager.init();
	cards = { card1, card2, card3, card4, card5, card6, card7, card8, card9, card10 };
	


	
	ids[0] = 1;
	ids[2] = 3;
	ids[4] = 5;
	ids[6] = 7;
	ids[8] = 9;
	
	tryAgainScreen = engine.LoadTexture("img\\tryagain3.bmp", presenter1.m_mainRenderer);
	background1 = engine.LoadTexture("img\\woodTable.bmp", presenter1.m_mainRenderer);
	Knife = engine.LoadTexture("img\\oneKnife.bmp", presenter1.m_mainRenderer);
	Yes = engine.LoadTexture("img\\YES.bmp", presenter1.m_mainRenderer);
	Beer1 = engine.LoadTexture("img\\Beer1.bmp", presenter1.m_mainRenderer);
	No = engine.LoadTexture("img\\No.bmp", presenter1.m_mainRenderer);
	setRandomPositions();


	
	
	


	
	
}



void Board::update() {
	

	

	
	

}


	
	
	








void Board::draw()
{
	presenter1.drawObject(background1);
	presenter1.drawObject(Knife, { 1300, 100, 50, 400 });
	presenter1.drawObject(Beer1, { 989,674, 200, 300 });

	if(reset == false){
		for (int z = 0; z < cards.size(); z++) {
			cards[z].draw();
			

		}
		
	}else if (ids.empty()) {
		tryAgain();

	}
	

	
	
	
	

	
	
	
		
	
}	



	
		

	
	
	
	
	



	
	
	


void Board::destroy()
{
	//player1.destroyPlayer();
	SDL_DestroyTexture(m_background);
	
}

void Board::resetGame()
{

	ids[0] = 1;
	ids[2] = 3;
	ids[4] = 5;
	ids[6] = 7;
	ids[8] = 9;

	std::cout << "dont work";
	std::fstream stream;
	stream.open("log.txt");

	// Write to the file
	stream << SDL_GetError();

	// Close the file
	stream.close();

	// Reset each card in the cards vector
	for (int cardsReset = 0; cardsReset < cards.size(); cardsReset++) {
		cards[cardsReset].reset();
		setRandomPositions();
		cards[cardsReset].show();
	}



}

bool Board::foundMap(int keyOrValue1, int keyOrValue2, std::map<int, int>& myMap)
{
	for (const auto& entry : myMap) {
		if ((entry.first == keyOrValue1 && entry.second == keyOrValue2) ||
			(entry.first == keyOrValue2 && entry.second == keyOrValue1)) {
			return true;
		}
	}
	return false;
}


void Board::eraseElementsByValue(std::map<int, int>& myMap, const int& valueToErase)
{
	
		auto it = myMap.begin();
		while (it != myMap.end()) {
			if (it->second == valueToErase) {
				it = myMap.erase(it);
				std::cout << "Element with value " << valueToErase << " erased." << std::endl;
			}
			else {
				++it;
			}
		}
	


}




void Board::handleCardSelection(int cardIndex)
{
	int mouseX, mouseY;

	static int firstClickIndex = 0;
	static int secondClickIndex = 0;
	static auto startTime = std::chrono::steady_clock::now();

	SDL_GetGlobalMouseState(&mouseX, &mouseY);

	std::cout << "MouseCoords: (" << mouseX << "," << mouseY << ")" << std::endl;

	

	// Card selection logic
	if (mousePressed == 1) {
		firstClickIndex = cardIndex;
		cards[firstClickIndex].changeTextureBack();
	}
	else if (mousePressed == 2) {
		secondClickIndex = cardIndex;
		cards[secondClickIndex].changeTextureBack();

		if (foundMap(firstClickIndex, secondClickIndex, ids)) {
			soundManager.playSound(CARDS_SAME);
			cards[firstClickIndex].hide();
			cards[secondClickIndex].hide();
			ids.erase(firstClickIndex);
			ids.erase(secondClickIndex);
			mousePressed = 0;
		}
		else {
			soundManager.playSound(CARDS_NOT_SAME);
			cards[firstClickIndex].changeTextureFront();
			cards[secondClickIndex].changeTextureFront();
			mousePressed = 0;
		}
	}
}


void Board::handleInput(SDL_Event& e)
{
	int mouseX, mouseY;

	static auto startTime = std::chrono::steady_clock::now(); // Record the start time

	SDL_GetGlobalMouseState(&mouseX, &mouseY);

	std::cout << "MouseCoords: (" << mouseX << "," << mouseY << ")" << std::endl;

	SDL_Rect mouseRect = { mouseX, mouseY, 0, 0 };

	if (colCheck.colliding(mouseRect, { 700, 500, 200, 200 }, 0, 0) && inpMan.mouseButtonPressed(e, 1) && reset == true) {
		
		resetGame();
		start = true;
		reset = false;
	}
	else if (colCheck.colliding(mouseRect, { 700, 700, 200, 200 }, 0, 0) && inpMan.mouseButtonPressed(e, 1) && reset == true) {
		SDL_Quit();
		exit(1);
		

	}
	if (reset) {
		soundManager.playSound(SUCCESS);
	}



	if (start) {
		auto currentTime = std::chrono::steady_clock::now();
		auto elapsedTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - startTime).count();

		// Show the cards for 4 seconds
		for (int cardsHint = 0; cardsHint < cards.size(); cardsHint++) {
			cards[cardsHint].changeTextureBack();

			if (elapsedTime >= showCardsDuration) {
				cards[cardsHint].changeTextureFront();
				start = false;
			}
		}
	}



	for (int h = 0; h < cards.size(); h++) {
		SDL_GetGlobalMouseState(&mouseX, &mouseY);
		mouseRect.x = mouseX;
		mouseRect.y = mouseY;


		

		

		// Show the cards for a specified duration
		
		
		if (!ids.empty() && inpMan.mouseButtonPressed(e, 1) && colCheck.colliding(mouseRect, cards[h].drawRect, 0, 0) && start == false) {
			
			
			soundManager.playSound(PLAYER_COLLISION);
			mousePressed++;
			handleCardSelection(h);
		}
		if (ids.empty()) {
			
			reset = true;
		}
		
	}
}









