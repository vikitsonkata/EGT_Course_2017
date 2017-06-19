/*
 * Game.cpp
 *
 *  Created on: 19.06.2017 ã.
 *      Author: Viktor
 */

#include "Game.h"

Game::Game()
{
	Init();
	LoadMedia();
	CropFromImage();
	DoRectsOnScreenGrid();
}

Game::~Game()
{
	Close();
}

void Game::Init()
{
	window = SDL_CreateWindow("text in window", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, BOARD_WIDTH, BOARD_HEIGHT, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//color on background if no picture
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
}

void Game::LoadMedia()
{
	SDL_Surface* surface = IMG_Load("ChessBoard.png");

	background = SDL_CreateTextureFromSurface(renderer, surface);

	surface = IMG_Load("Chess--Pieces.png");

	pictures = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 181, 230, 29));

	if(background == NULL || pictures == NULL)
		cerr << "Failed to load all the media!";
	SDL_FreeSurface(surface);
}

void Game::Close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(pictures);
}

void Game::RenderBackground()
{
	SDL_RenderCopy(renderer, background, NULL, NULL);
}

void Game::RenderPiece(int picturePos, int screenPos)
{
	SDL_RenderCopy(renderer, pictures, &possisionsFromTexture[picturePos],
			&possisionsOnScreen[screenPos]);
}

SDL_Renderer* Game::getRenderer() const
{
	return renderer;
}

void Game::CropFromImage()
{

	for (int j = 0; j < 2; j++)
	{

		for (int i = 0; i < 6; i++)
		{
			SDL_Rect rect = { i * PIECE_WIDTH, j * PIECE_HEIGHT, PIECE_WIDTH,
					PIECE_HEIGHT };
			possisionsFromTexture.push_back(rect);
		}
	}
}
void Game::DoRectsOnScreenGrid()
{
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			SDL_Rect rect = { i * BOARD_WIDTH / 8, j
					* BOARD_HEIGHT / 8, BOARD_WIDTH / 8,
					BOARD_HEIGHT / 8 };
			possisionsOnScreen.push_back(rect);
		}
	}
}
