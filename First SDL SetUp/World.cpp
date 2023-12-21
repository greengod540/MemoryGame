#include "World.h"
#include <Presenter.h>
#include <Board.h>
#include <SoundManager.h>
Board m_board;
World::World()
{
    m_running = true;
}

World::~World()
{

}

void World::init()
{
    
    m_presenter.init();

    m_board.init();
    m_soundManager.init();
}

void World::run()
{
    m_presenter.Draw();
   
    
    
    m_board.draw();
    SDL_Event e;
    m_board.update();
    while (SDL_PollEvent(&e)) {
        m_board.handleInput(e);
       
        





    }

    
    
}

void World::destroy()
{
   
}

bool World::isRunning()
{
    return m_running;
}