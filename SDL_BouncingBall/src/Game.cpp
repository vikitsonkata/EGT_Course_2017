/*
 * Game.cpp
 *
 *  Created on: 20.06.2017 г.
 *      Author: Viktor
 */

#include "Game.h"

Game::Game()
{
	Init();
	LoadMedia();
	rect =
	{	0, 0, BALL_WIDTH, BALL_HEIGHT};

	angle = 0;
	horizontalReverse = false;
	verticalReverse = false;
}

Game::~Game()
{
	Close();
}

void Game::RenderBackgraound()
{
	SDL_SetRenderDrawColor(renderer, 0, 200, 100, 1);
	SDL_RenderPresent(renderer);
}

void Game::HandleEvent(SDL_Event e)
{
	if (e.type == SDL_KEYDOWN || e.key.repeat == 0)
		switch (e.key.keysym.sym)
		{
		case SDLK_LEFT:
			angle += ANGLE_STEP;
			if (rect.x <= 0)
				horizontalReverse = !horizontalReverse;
			else
				rect.x -= BALL_STEP; //+ 2 * horizontalReverse;
			break;
		case SDLK_RIGHT:
			angle -= ANGLE_STEP;
			if (rect.x >= WINDOW_WIDTH - BALL_WIDTH)
				horizontalReverse = !horizontalReverse;
			else
				rect.x += BALL_STEP; // - 2 * horizontalReverse;
			break;
		case SDLK_UP:
			angle += ANGLE_STEP;
			if (rect.y <= 0)
				verticalReverse = !verticalReverse;
			else
				rect.y -= BALL_STEP; // + 2 * verticalReverse;
			break;
		case SDLK_DOWN:
			angle -= ANGLE_STEP;
			if (rect.y >= WINDOW_HEIGHT - BALL_HEIGHT)
				verticalReverse = !verticalReverse;
			else
				rect.y += BALL_STEP; // - 2 * verticalReverse;
			break;
		}
}

void Game::Move()
{
	SDL_RenderCopyEx(renderer, ballTexture, NULL, &rect, angle, NULL,
			SDL_FLIP_NONE);
	SDL_Delay(4);
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Game::getRenderer()
{
	return renderer;
}

void Game::Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(ballTexture);
}

void Game::Init()
{
	window = SDL_CreateWindow("Bouncing Ball", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 111, 111, 111, 0);

}

void Game::LoadMedia()
{
	SDL_Surface* surface = IMG_Load("ball.png");

	ballTexture = SDL_CreateTextureFromSurface(renderer, surface);

	if (ballTexture == NULL)
		cerr << "Failed to load media!";

	SDL_FreeSurface(surface);
}

