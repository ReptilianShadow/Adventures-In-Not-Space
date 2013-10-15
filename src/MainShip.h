/*
 * MainShip.h
 *
 *  Created on: Oct 14, 2013
 *      Author: brian
 */

#ifndef MAINSHIP_H_
#define MAINSHIP_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class MainShip {
public:
	MainShip();
	virtual ~MainShip();

	void render();

};

#endif /* MAINSHIP_H_ */
