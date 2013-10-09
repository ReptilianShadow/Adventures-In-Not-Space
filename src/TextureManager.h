/*
 * TextureManager.h
 *
 *  Created on: Oct 6, 2013
 *      Author: brian
 */

#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager{

public:
	bool load(std::string fileName,std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
			SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame,
			SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*>m_textureMap;

};


#endif /* TEXTUREMANAGER_H_ */
