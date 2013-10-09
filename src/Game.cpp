/*
 * Game.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: brian
 */

#include "Game.h"


using namespace std;

Game::Game() {
	// TODO Auto-generated constructor stub


	m_bRunning = true;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

bool Game::init(const char * windowTitle, int xPos, int yPos, int width, int height, int sdlWindowflags){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cerr <<  "SDL_Init" << endl;
		return false;
	}
	cout << "SDL_Init Sucessful" << endl;
	//initialize sdl_image libraries to avoid later delay
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		cerr << "IMG_Init" << endl;
		return false;
	}
	cout << "SDL_image init Successful" << endl;


	window = SDL_CreateWindow(windowTitle, xPos, yPos, width, height, sdlWindowflags);
	if (window == NULL){
		cerr << "CreateWindow" << endl;
		return false;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL){
		cerr << "CreateRenderer" << endl;
		return false;
	}

	SDL_SetRenderDrawColor(renderer, 50, 0, 50, 255);

	return true;
}

void Game::checkInput(){
	SDL_Event e;
	while (SDL_PollEvent(&e)){

		if (e.type == SDL_KEYDOWN){

		}else if (e.type == SDL_KEYUP){

		}
		if (e.type == SDL_QUIT) gameQuit = true;
	}
}

void Game::update(){

	//do game physics and such

}

void Game::render(){
	SDL_RenderClear(renderer);



	SDL_RenderPresent(renderer);

}

void Game::cleanup(){
	//maybe not necessary
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);


	IMG_Quit();
	SDL_Quit();
}
