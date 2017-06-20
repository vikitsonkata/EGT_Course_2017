/*
 * Game.h
 *
 *  Created on: 20.06.2017 ã.
 *      Author: Viktor
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

class Game
{
public:
	Game();
	virtual ~Game();

	void RenderRandomRect();

	SDL_Renderer* getRenderer();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* background;
	SDL_Texture* rects;

	void Init();
	void LoadMedia();
	void Close();


};

#endif /* GAME_H_ */
