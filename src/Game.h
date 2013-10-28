/*
 * Game.h
 *
 *  Created on: Oct 8, 2013
 *      Author: brian
 */

#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "TextureManager.h"

class Game {
public:
	Game();
	~Game();

	// simply set the running variable to true
	bool init(const char * windowTitle, int xPos, int yPos, int width, int height, int sdlWindowflags);

	void render();
	void update();
	void checkInput();
	void cleanup();

	// a function to access the private running variable
	bool running() { return m_bRunning; }
	bool quitRequested() {return gameQuit;}

	static SDL_Window *window;
	static SDL_Renderer *renderer;

private:

	//SDL initialization
	bool initSDLStuff(const char * windowTitle, int xPos, int yPos, int width, int height, int sdlWindowflags);

	bool gameQuit;
	bool m_bRunning;

	int screenWidth, screenHeight;

};

#endif /* GAME_H_ */
