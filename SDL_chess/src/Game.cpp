/*
 * Game.cpp
 *
 *  Created on: 19.06.2017 ã.
 *      Author: Viktor
 */

#include "Game.h"

Game::Game() {
	Init();
	LoadMedia();
	Crop();
	DoRectsOnScreenGrid();
}

Game::~Game() {
	Close();
}

void Game::Init() {
	window = SDL_CreateWindow("text in window", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);

}

void Game::LoadMedia() {
	SDL_Surface* surface = IMG_Load("ChessBoard.png");

	background = SDL_CreateTextureFromSurface(renderer, surface);

	surface = IMG_Load("Chess--Pieces.png");

	pictures = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void Game::Close() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(pictures);
}

void Game::RenderBackground() {
	SDL_RenderCopy(renderer, background, NULL, NULL);
}

void Game::RenderPiece(int picturePos, int screenPos) {
	SDL_RenderCopy(renderer, pictures, &possisionsFromTexture[picturePos],NULL);
//			&possisionsOnScreen[screenPos]);
}

SDL_Renderer* Game::getRenderer() const {
	return renderer;
}

void Game::Crop() {
	SDL_Rect rect = { 0, 0, PIECE_WIDTH, PIECE_HEIGHT };

	for (int j = 0; j < 2; j++) {

		for (int i = 0; i < 6; i++) {
			possisionsFromTexture.push_back(rect);
			rect.x += PIECE_WIDTH;
		}
		rect.x = 0;
		rect.y = PIECE_HEIGHT;
	}
}
void Game::DoRectsOnScreenGrid()
{
	SDL_Rect rect = {0,0,TEXTURE_SCREEN_WIDTH / 8, TEXTURE_SCREEN_HEIGHT / 8};

	for(int j = 0; j < 8; j++)
	{
		for(int i = 0; i < 8; i++)
		{
			possisionsOnScreen.push_back(rect);
			rect.x += TEXTURE_SCREEN_WIDTH / 8;
		}
		rect.x = 0;
		rect.y += TEXTURE_SCREEN_HEIGHT / 8;
	}
}
