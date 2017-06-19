//============================================================================
// Name        : SDL_Help_Vaniugata.cpp
// Author      : vc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"
#include <iostream>
using namespace std;

int main(int args, char* argc[]) {
	Game game;

	game.RenderBackground();
	SDL_RenderPresent(game.getRenderer());

	bool quit = false;
	SDL_Event e;

	while(!quit)
	{
		game.RenderBackground();
		while(SDL_PollEvent(&e) > 0)
		{
			if(e.key.keysym.sym == SDLK_q)
				quit = true;

			switch(e.type)
			{
			case SDL_QUIT:
				{
					quit = true;
					break;
				}
			case SDL_MOUSEBUTTONDOWN:
				{
					game.RenderPiece(0,0);
					SDL_RenderPresent(game.getRenderer());
					break;
				}

			}

		}

	}

	return 0;
}
