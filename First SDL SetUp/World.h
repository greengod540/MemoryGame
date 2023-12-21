#pragma once
#include <Presenter.h>
#include <SoundManager.h>
#include <InputManager.h>
class World
{
public:

	Presenter m_presenter;
	InputManager m_inputManager;
	SoundManager m_soundManager;


	World();
	~World();
	void init();
	void run();
	void destroy();

	bool isRunning();

	

private:
	bool m_running;
};

