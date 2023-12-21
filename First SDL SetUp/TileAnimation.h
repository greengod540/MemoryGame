#pragma once
#include <string>
#include <fstream>
#include <SDL.h>
#include <filesystem>
class TileAnimation
{
public:
    struct Rects {
        SDL_Rect srcRect;
        SDL_Rect dstRect;
        int xMargin;
        int yMargin;
    };


    Rects rect;
    int frame = 0; 
    int row = 0;
    


    Rects getFrames(int framesToPlay, std::string configFilePath, int row1, int frame);

    int UpdateFrame(std::string configFilePath, int framesToPlay, bool repeat);

    SDL_Rect returnSrcRect(int framesToPlay, std::string configFilePath, int row1, int frame);

    int getCurrentFrame();
};


