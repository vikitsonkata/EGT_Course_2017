/*
 * Game.cpp
 *
 *  Created on: 20.06.2017 ã.
 *      Author: Viktor
 */

#include "Game.h"

Game::Game()
{
	Init();
	LoadMedia();
}

Game::~Game()
{
	Close();
}

void Game::Init()
{
	window = SDL_CreateWindow("Press space for random rectangle",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
			WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 0);
}

void Game::LoadMedia()
{

}

void Game::Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(rects);
}

void Game::RenderRandomRect()
{
	srand(time(NULL));
	int rectWidth = rand() % WINDOW_WIDTH;
	int rectHeight = rand() % WINDOW_HEIGHT;
	int rectX = rand() % (WINDOW_WIDTH - rectWidth);
	int rectY = rand() % (WINDOW_HEIGHT - rectHeight);
	SDL_Rect rect = { rectX, rectY, rectWidth, rectHeight };
	SDL_SetRenderDrawColor(renderer,
			rand() % 255, rand() % 255, rand() % 255, 0);
	SDL_RenderFillRect(renderer, &rect);
}

SDL_Renderer* Game::getRenderer()
{
	return renderer;
}

