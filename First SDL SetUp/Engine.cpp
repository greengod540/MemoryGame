#include "Engine.h"

SDL_Texture* Engine::LoadTexture(std::string imagePathBMP, SDL_Renderer* renderer) {  
    SDL_Surface* surface = SDL_LoadBMP(imagePathBMP.c_str());

    SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (Texture == nullptr) {
        
        imagePathBMP = "img\\Null.bmp";
        SDL_Surface* surface1 = SDL_LoadBMP(imagePathBMP.c_str());

        SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, surface1);

        SDL_FreeSurface(surface);
        return Texture;


    }
    SDL_FreeSurface(surface);
    return Texture;
}

bool Engine::colliding(drawDstRect objectRect, drawDstRect targetRect, int offsetx, int offsety){
    bool checkCollision = false;
    if (objectRect.dstRect.y + objectRect.dstRect.h + offsety > targetRect.dstRect.y && objectRect.dstRect.y < targetRect.dstRect.y + targetRect.dstRect.h) {
        checkCollision = true;
        return checkCollision;
    }


    if (objectRect.dstRect.x + objectRect.dstRect.w + offsetx > targetRect.dstRect.x && objectRect.dstRect.x < targetRect.dstRect.x + targetRect.dstRect.w) {
        checkCollision = true;
        return checkCollision;
    }


    return checkCollision;


    
}

