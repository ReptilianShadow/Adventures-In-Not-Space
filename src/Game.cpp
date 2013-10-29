/*
 * Game.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: brian
 */

#include "Game.h"

#include <math.h>

using namespace std;

Game::Game() {
	Game::renderer = NULL;
	gameRunning = true;
	Game::window = NULL;

	screenWidth = 0;
	screenHeight = 0;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

bool Game::init(const char * windowTitle, int xPos, int yPos, int width, int height, int sdlWindowflags){

	screenWidth = width;
	screenHeight = height;

	//if SDL initialization fails
	if (!initSDLStuff(windowTitle, xPos, yPos, width, height, sdlWindowflags)){
		cout << "SDL Init Fail" << endl;
		return false;
	}

	cout << "Game Initialization Successful" << endl;

	//create keymap, it updates states without further calls
	//only SDL_PumpEvents(); is required, but that's included with
	//SDLPollEvent
	keymap = SDL_GetKeyboardState(0);

	//load all necessary texture here?
	//I'm not sure  if you should load all textures at startup
	//or if I should dynamically load them.. the latter would make sense
	//to preserve memory usage but idk...
	TextureManager::getInstance()->load("assets/ship.png", "ship");



	shipX = screenWidth / 2;
	shipY = screenHeight / 2;



	return true;
}

void Game::checkInput(){

	//Do per event actions

	SDL_Event event;
	while (SDL_PollEvent(&event)){

		if (event.type == SDL_KEYDOWN){

			SDL_Keycode keyPressed = event.key.keysym.sym;

			switch(keyPressed){
			case SDLK_ESCAPE:
				gameRunning = false;
				break;

			}
		}else if (event.type == SDL_KEYUP){

		}
		if (event.type == SDL_QUIT) gameRunning = false;
	}


	//check key states for actions to be done


	if (getKeyState(SDLK_LEFT)){
		shipX -=7;
	}
	if (getKeyState(SDLK_RIGHT)){
		shipX +=7;
	}
	if (getKeyState(SDLK_UP)){
		shipY -=7;
	}
	if (getKeyState(SDLK_DOWN)){
		shipY +=7;
	}

}

bool Game::getKeyState(SDL_Keycode keyToCheckPress){
	return keymap[ (Uint8) keyToCheckPress];
}

void Game::update(){

	//do game physics and such



}

void Game::render(){
	SDL_RenderClear(Game::renderer);


	TextureManager::getInstance()->draw("ship", shipX, shipY,50,50,SDL_FLIP_NONE);


	SDL_RenderPresent(Game::renderer);

}

void Game::cleanup(){
	//maybe not necessary
	SDL_DestroyRenderer(Game::renderer);
	SDL_DestroyWindow(Game::window);


	IMG_Quit();
	SDL_Quit();
}


bool Game::initSDLStuff(const char * windowTitle, int xPos, int yPos, int width, int height, int sdlWindowflags){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cerr <<  "Error Initializing: SDL_Init" << endl;
		return false;
	}
	cout << "SDL_Init Sucessful" << endl;
	//initialize sdl_image libraries to avoid later delay
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		cerr << "Error Initializing: IMG_Init" << endl;
		return false;
	}
	cout << "SDL_image init Successful" << endl;


	Game::window = SDL_CreateWindow(windowTitle, xPos, yPos, width, height, sdlWindowflags);
	if (Game::window == NULL){
		cerr << "Error Creating: CreateWindow" << endl;
		return false;
	}
	Game::renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Game::renderer == NULL){
		cerr << "Error Creating: CreateRenderer" << endl;
		return false;
	}

	SDL_SetRenderDrawColor(Game::renderer, 50, 0, 50, 255);

	return true;
}
