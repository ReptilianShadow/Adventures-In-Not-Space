/*
 * TextureManager.cpp
 *
 *  Created on: Oct 6, 2013
 *      Author: brian
 */

#include "TextureManager.h"

TextureManager* TextureManager::instance = NULL;

TextureManager* TextureManager::getInstance(){

	if (!instance) instance = new TextureManager;

	return instance;

}



bool TextureManager::load(std::string fileName, std::string id)
{

	std::cout << id << " loaded" << std::endl;
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());

	if(pTempSurface == 0)
	{
		return false;
	}

	SDL_Texture* pTexture =
			SDL_CreateTextureFromSurface(Game::renderer, pTempSurface);

	SDL_FreeSurface(pTempSurface);

	// everything went ok, add the texture to our list
	if(pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}

	// reaching here means something went wrong
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(Game::renderer, m_textureMap[id], &srcRect,
			&destRect, 0, 0, flip);
}


void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame, SDL_RendererFlip flip){
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;

	SDL_RenderCopyEx(Game::renderer, m_textureMap[id], &srcRect,
			&destRect, 0, 0, flip);
}

SDL_Texture* TextureManager::getTexture(std::string id){
	return m_textureMap[id];
}



