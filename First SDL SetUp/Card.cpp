#include "Card.h"
#include <Presenter.h>
#include <TextureLoader.h>
#include <defines.h>
#include <iostream>

TextureLoader Card::textureLoaderCard;
Presenter presenter_Card;
std::string backimg, frontimg;

Card::Card()
{
}

Card::~Card()
{
}

void Card::init(std::string configFile)
{
    std::fstream stream;
    std::string tmp;

    stream.open(configFile);
    stream >> tmp >> backimg >> frontimg;
    stream >> tmp >> dstRect.x >> dstRect.y >> dstRect.w >> dstRect.h;
    stream >> tmp >> card.dstRect.x >> card.dstRect.y >> card.dstRect.w >> card.dstRect.h;
    stream >> tmp >> card.srcRect.x >> card.srcRect.y >> card.srcRect.w >> card.srcRect.h;

    back = textureLoaderCard.CreateTexture(backimg, presenter_Card.m_mainRenderer);
    front = textureLoaderCard.CreateTexture(frontimg, presenter_Card.m_mainRenderer);

    card.texture = back;

    

    // Initialize drawRect based on the random value
    
   

}

void Card::reset()
{
    card.texture = back;

    // Reset random value
    random = std::rand() % 2 + 1;

    // Initialize drawRect based on the random value
    if (random == 1) {
        drawRect = card.dstRect;
    }
    else {
        drawRect = dstRect;
    }

}



void Card::destroy()
{
    SDL_DestroyTexture(back);
    SDL_DestroyTexture(front);
}

void Card::draw()
{
    

    if (isVisible == true) {
        presenter_Card.drawObject(card.texture, drawRect);
    }

   
}


void Card::changeTextureBack()
{
    if (card.texture == back)
    {
        card.texture = front;
    }
}

void Card::changeTextureFront()
{
    if (card.texture == front)
    {
        card.texture = back;
    }
}

int Card::getCardID()
{
    return Card::ID;
}

void Card::setCardID(int setID)
{
    Card::ID = setID;
}

void Card::hide()
{
    isVisible = false;
}

void Card::show()
{
    isVisible = true;
}
