//============================================================================
// Name        : SDL_BouncingBall.cpp
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

	game.RenderBackgraound();
	SDL_RenderPresent(game.getRenderer());

	bool quit = false;
	SDL_Event e;

	while(!quit)
	{
		while(SDL_PollEvent(&e) > 0)
		{
			if(e.key.keysym.sym == SDLK_q
				||	e.type == SDL_QUIT)
				quit = true;

			game.HandleEvent(e);
		}

		SDL_RenderClear(game.getRenderer());
		game.Move();
		SDL_RenderPresent(game.getRenderer());
	}
}
