/*
 * Game.h
 *
 *  Created on: 19.06.2017 ã.
 *      Author: Viktor
 */

#ifndef GAME_H_
#define GAME_H_
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
using namespace std;

const int TEXTURE_SCREEN_WIDTH = 2000;
const int TEXTURE_SCREEN_HEIGHT = 667;

const int PIECE_WIDTH = TEXTURE_SCREEN_WIDTH / 6;
const int PIECE_HEIGHT = TEXTURE_SCREEN_HEIGHT / 2;

class Game {
public:
	Game();
	virtual ~Game();

	void RenderBackground();
	void RenderPiece(int = 0, int = 0);

	SDL_Renderer* getRenderer() const;

private:
	void Init();
	void LoadMedia();
	void Close();

	void Crop();
	void DoRectsOnScreenGrid();

	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Texture* background;
	SDL_Texture* pictures;

	vector<SDL_Rect> possisionsOnScreen;
	vector<SDL_Rect> possisionsFromTexture;
};

#endif /* GAME_H_ */
