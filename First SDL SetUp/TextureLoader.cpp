#include "TextureLoader.h"
#include <SDL.h>

SDL_Texture* TextureLoader::CreateTexture(std::string imagePathBMP, SDL_Renderer* renderer) {
    imagePathBMP = "img\\" + imagePathBMP;
    SDL_Surface* surface = SDL_LoadBMP(imagePathBMP.c_str());
    std::cout << SDL_GetError();

    if (surface == nullptr) {
        // Loading failed, load a default texture or handle the error accordingly
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        imagePathBMP = "img\\null.bmp";
        surface = SDL_LoadBMP(imagePathBMP.c_str());
        if (surface == nullptr) {
            std::cerr << "Error loading null.bmp: " << SDL_GetError() << std::endl;
            return nullptr; // Return nullptr to signal the failure
        }
    }

    SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    return Texture;
}

