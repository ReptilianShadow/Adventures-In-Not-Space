/*
 * MainShip.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: brian
 */

#include "MainShip.h"

MainShip::MainShip() {
	// TODO Auto-generated constructor stub

}

MainShip::~MainShip() {
	// TODO Auto-generated destructor stub
}

void MainShip::render(){

	int shipWidth = 0, shipHeight = 0;
		//SDL_QueryTexture(texManager.getTexture("ship"), 0, 0, &shipWidth, &shipHeight);
		TextureManager::getInstance()->draw("ship", 0, 0, shipWidth, shipHeight, SDL_FLIP_NONE);

}
