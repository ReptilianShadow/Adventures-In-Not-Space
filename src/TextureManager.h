/*
 * TextureManager.h
 *
 *  Created on: Oct 6, 2013
 *      Author: brian
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <map>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager{

public:



	bool TextureManager::load(std::string fileName, std::string id);

	void draw(std::string id, int x, int y, int width, int height,
			SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
			SDL_RendererFlip flip = SDL_FLIP_NONE);

	SDL_Texture* getTexture(std::string id);

	static TextureManager* getInstance(); //if an instance does not exist, create one, and return it

private:
	//class instance for singleton
	static TextureManager* instance;

	//private constructor because its a singleton
	TextureManager(){};


	std::map<std::string, SDL_Texture*>m_textureMap;

};


#endif /* TEXTUREMANAGER_H_ */
