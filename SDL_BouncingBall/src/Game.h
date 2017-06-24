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
#include <iostream>
using namespace std;

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

const int BALL_WIDTH = 50;
const int BALL_HEIGHT = 50;

const int BALL_STEP = 5;
const int ANGLE_STEP = 5;

class Game
{
public:
	Game();
	virtual ~Game();

	void RenderBackgraound();
	void HandleEvent(SDL_Event );
	void Move();

	SDL_Renderer* getRenderer();

	void Close();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* ballTexture;
	SDL_Rect rect;

	void Init();
	void LoadMedia();

	int angle;
	bool horizontalReverse;
	bool verticalReverse;
};

#endif /* GAME_H_ */
