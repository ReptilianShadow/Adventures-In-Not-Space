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
#include "MainShip.h"

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
	bool running() { return gameRunning; }
	bool quitRequested() {return !gameRunning;}

	static SDL_Window* window;
	static SDL_Renderer* renderer;

private:

	//SDL initialization
	bool initSDLStuff(const char * windowTitle, int xPos, int yPos, int width, int height, int sdlWindowflags);

	//return true if key is down, false if up
	//use values SDLK_*
	bool getKeyState(SDL_Keycode);

	bool gameRunning;

	int screenWidth, screenHeight;

	const Uint8 * keymap;

	int shipX, shipY;



};

#endif /* GAME_H_ */
