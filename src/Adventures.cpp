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

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



Game* g_game = new Game();

int main(int argc, char **argv) {

	g_game->init("Adventures in (Not) Space", 50, 50, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	while (!g_game->quitRequested()){

		g_game->checkInput();
		g_game->update();
		g_game->render();
	}

	g_game->cleanup();

	return 0;

}





