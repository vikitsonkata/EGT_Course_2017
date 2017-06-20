//============================================================================
// Name        : SDL_RandomButton.cpp
// Author      : vc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"
using namespace std;

int main(int args, char* argc[])
{
	Game game;

	SDL_RenderPresent(game.getRenderer());

	bool quit = false;
	SDL_Event e;

	while(!quit)
	{
		while(SDL_PollEvent(&e) > 0)
		{
			switch(e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch(e.key.keysym.sym)
				{
				case SDLK_q:
					quit = true;
					break;
				case SDLK_SPACE:
					game.RenderRandomRect();
					SDL_RenderPresent(game.getRenderer());
					break;
				}
			}
		}
	}

	return 0;

}
