#include "CollisionCheck.h"

bool CollisionCheck::colliding(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety) {
    bool checkCollisionX = false;
    bool checkCollisionY = false;

    
    if (objectRect.y + objectRect.h + offsety >= targetRect.y && objectRect.y <= targetRect.y + targetRect.h) {
        checkCollisionY = true;
    }


    if (objectRect.x + objectRect.w + offsetx >= targetRect.x && objectRect.x <= targetRect.x + targetRect.w) {
        checkCollisionX = true;
    }
    
    
    return checkCollisionX && checkCollisionY;
}

bool CollisionCheck::collidingX(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety)
{
    if (objectRect.x + objectRect.w + offsetx > targetRect.x && objectRect.x < targetRect.x + targetRect.w) {
        return true;
    }
    else {
        return false;
    }
}

bool CollisionCheck::collidingY(SDL_Rect objectRect, SDL_Rect targetRect, int offsetx, int offsety)
{
    if (objectRect.y + objectRect.h + offsety > targetRect.y && objectRect.y < targetRect.y + targetRect.h) {
        return true;
    }
    else {
        return false;
    }
}

