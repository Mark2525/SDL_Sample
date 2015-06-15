#include	<SDL.h>
#include	<iostream>

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;
int main(int argc, char* argv[])
{
	bool quit = false;
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;

	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
	{
		cout << "SDL Init Error : " << SDL_GetError() << endl;
	}else{
		window = SDL_CreateWindow("TEST CREATE SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);	
		screen = SDL_GetWindowSurface(window);
		if(window == NULL)
		{
			cout << "Error Create Window : " << SDL_GetError() << endl;
		}else{
			SDL_Event e;

			while(!quit)
			{
				while(SDL_PollEvent(&e)!=0)
				{
					if(e.type == SDL_QUIT)
					{
						quit = true;
						break;
					}
				}

				SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFFFFFF, 0x000000, 0x000000));
				SDL_UpdateWindowSurface(window);
			} 
		}
	}

	SDL_FreeSurface(screen);
	screen=NULL;

	SDL_DestroyWindow(window);
	window=NULL;

	SDL_Quit();


	return 0;
}