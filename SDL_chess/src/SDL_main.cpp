//============================================================================
// Name        : SDL_Help_Vaniugata.cpp
// Author      : vc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Game.h"
using namespace std;

void ShowFigure(Game&, int);

int main(int args, char* argc[])
{
	Game game;

	game.RenderBackground();
	SDL_RenderPresent(game.getRenderer());

	bool quit = false;
	SDL_Event e;
	int counter = 0;
	while (!quit)
	{
		while (SDL_PollEvent(&e) > 0)
		{
			if (e.key.keysym.sym == SDLK_q)
				quit = true;

			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			case SDL_MOUSEBUTTONDOWN:
				ShowFigure(game, counter);
				SDL_RenderPresent(game.getRenderer());
				counter++;
				break;
			}

		}

	}

	return 0;
}

void ShowFigure(Game& game, int counter)
{
	switch (counter)
	{
	case 0:
		game.RenderPiece('w', 'r', counter / 8, counter % 8);
		break;
	case 1:
		game.RenderPiece('w', 'h', counter / 8, counter % 8);
		break;
	case 2:
		game.RenderPiece('w', 'b', counter / 8, counter % 8);
		break;
	case 3:
		game.RenderPiece('w', 'k', counter / 8, counter % 8);
		break;
	case 4:
		game.RenderPiece('w', 'q', counter / 8, counter % 8);
		break;
	case 5:
		game.RenderPiece('w', 'b', counter / 8, counter % 8);
		break;
	case 6:
		game.RenderPiece('w', 'h', counter / 8, counter % 8);
		break;
	case 7:
		game.RenderPiece('w', 'r', counter / 8, counter % 8);
		break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		game.RenderPiece('w', ' ', counter / 8, counter % 8);
		break;
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
	case 21:
	case 22:
	case 23:
		game.RenderPiece('b', ' ', counter / 8, counter % 8);
		break;
	case 24:
		game.RenderPiece('b', 'r', counter / 8, counter % 8);
		break;
	case 25:
		game.RenderPiece('b', 'h', counter / 8, counter % 8);
		break;
	case 26:
		game.RenderPiece('b', 'b', counter / 8, counter % 8);
		break;
	case 27:
		game.RenderPiece('b', 'k', counter / 8, counter % 8);
		break;
	case 28:
		game.RenderPiece('b', 'q', counter / 8, counter % 8);
		break;
	case 29:
		game.RenderPiece('b', 'b', counter / 8, counter % 8);
		break;
	case 30:
		game.RenderPiece('b', 'h', counter / 8, counter % 8);
		break;
	case 31:
		game.RenderPiece('b', 'r', counter / 8, counter % 8);
		break;
	}
}
