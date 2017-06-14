//============================================================================
// Name        : SDL_exercise.cpp
// Author      : vc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//Using SDL and standard IO
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <iostream>
#include <vector>
#include "Texture.h"
using namespace std;

const int SCREEN_WIDTH = 300;
const int SCREEN_HEIGHT = 300;

const int TEXTURE_WIDTH = 100;
const int TEXTURE_HEIGHT = 100;

static bool playerTurn = true;

SDL_Window* gWindow = NULL;

Texture gTexture;
Texture gPlayerTexture;

bool Init();
bool LoadMedia();
bool PlacePlayerIcon(int x, int y, SDL_Rect* playerRect);
bool GameOver(int isPlayed[3][3]);

int main(int args, char* argc[]) {
	Init() ? std::cerr << "" : std::cerr << "Failed to initialize sdl.";
	LoadMedia() ? std::cerr << "" : std::cerr << "Failed to load media.";
	bool quit = false;
	SDL_Event e;
	//Free renderer for game loop
	SDL_RenderClear(Texture::gRenderer);

	//SDL_RenderClear(Texture::gRenderer);
	SDL_Rect backgroundRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	gTexture.Render(0, 0, &backgroundRect);

	SDL_Rect playerRect;
	playerRect.w = TEXTURE_WIDTH;
	playerRect.h = TEXTURE_HEIGHT;
	playerRect.x = 0;
	playerRect.y = 100;

	int isPlayed[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			isPlayed[i][j] = 0;

	while (!quit) {

		SDL_RenderPresent(Texture::gRenderer);
		while (SDL_PollEvent(&e) != 0) {
			if(e.key.keysym.sym == SDLK_q)
				quit = true;
			switch (e.type) {
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_MOUSEBUTTONDOWN: {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (!isPlayed[x / TEXTURE_WIDTH][y / TEXTURE_HEIGHT]) {
					isPlayed[x / TEXTURE_WIDTH][y / TEXTURE_HEIGHT] += true
							+ playerTurn;
					PlacePlayerIcon(x, y, &playerRect);
				}
				if (GameOver(isPlayed)) {
						cout << "Wins player " << playerTurn << endl;
						SDL_RenderPresent(Texture::gRenderer);
						SDL_Delay(2000);
						quit = true;
					}
				break;
			}
			}
		}
	}
	return 0;
}

bool GameOver(int isPlayed[3][3]) {
	bool gameOver = false;
	if ((isPlayed[0][0] == isPlayed[1][1] && isPlayed[0][0] == isPlayed[2][2]
			&& isPlayed[0][0] != 0)
			|| (isPlayed[0][2] == isPlayed[1][1]
					&& isPlayed[0][2] == isPlayed[0][2] && isPlayed[0][2] != 0))
		gameOver = true;
	for (int i = 0; i < 3; i++)
		if ((isPlayed[i][0] == isPlayed[i][1]
				&& isPlayed[i][0] == isPlayed[i][2] && isPlayed[i][0] != 0)
				|| (isPlayed[0][i] == isPlayed[1][i]
						&& isPlayed[0][i] == isPlayed[2][i]
						&& isPlayed[0][i] != 0))
			gameOver = true;
	return gameOver;

}

bool Init() {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "Could not initialize SDL: " << SDL_GetError();
		return false;
	}
	//Create window
	gWindow = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		std::cerr << "Window could not be created: " << SDL_GetError();
		return false;
	}
	//Create renderer for window
	Texture::gRenderer = SDL_CreateRenderer(gWindow, -1,
			SDL_RENDERER_ACCELERATED);
	if (Texture::gRenderer == NULL) {
		std::cerr << "Failed to create renderer.";
		return false;
	}
	//Fill screen with selected color
	SDL_SetRenderDrawColor(Texture::gRenderer, 255, 255, 255, 0);
	//Initialize PNG loading
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cerr << "SDL image could not initialize: " << SDL_GetError();
		return false;
	}
	return true;
}

bool LoadMedia() {
	if (!gTexture.LoadFromFile("checkboard.png")) {
		std::cerr << "Failed to load texture.";
		return false;
	}
	if (!gPlayerTexture.LoadFromFile("players.png")) {
		std::cerr << "Failed to load texture.";

		return false;
	}
	return true;
}

bool PlacePlayerIcon(int x, int y, SDL_Rect* playerRect) {
	int xPos = 0, yPos = 0;
	xPos = x / playerRect->w * playerRect->w;
	yPos = y / playerRect->h * playerRect->h;

	if (playerTurn) {
		playerRect->y = 100;
		playerTurn = false;
	}
	else {
		playerRect->y = 0;
		playerTurn = true;
	}
	gPlayerTexture.Render(xPos, yPos, playerRect);

	return playerTurn;
}
