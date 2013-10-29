//============================================================================
// Name        : Adventures.cpp
// Author      : Brian Decker
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

const int INIT_SCREEN_WIDTH = 640;
const int INIT_SCREEN_HEIGHT = 480;

Game* g_game = new Game();

SDL_Window *Game::window = NULL;
SDL_Renderer *Game::renderer = NULL;

int main(int argc, char **argv) {

	g_game->init("Adventures in (Not) Space", 50, 50, INIT_SCREEN_WIDTH, INIT_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	while (!g_game->quitRequested()){

		g_game->checkInput();
		g_game->update();
		g_game->render();
	}

	g_game->cleanup();


	cout << "Main() end." << endl;
	return 0;

}





