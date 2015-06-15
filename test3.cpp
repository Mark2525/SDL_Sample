#include <SDL.h>
#include <iostream>


const int screenWidth = 600;
const int screenHeight = 400;

SDL_Window* window;
SDL_Surface* screen;
SDL_Surface* getimage;
SDL_Surface* getimage2;

int main(int argc, char* argv[])
{
	std::cout << argc << " : " << argv[1] << std::endl;

	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	screen = SDL_GetWindowSurface(window);

	getimage = SDL_LoadBMP("imageBMP.bmp");

	getimage2 = SDL_LoadBMP("hello_world.bmp");

	SDL_Event e;

	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
				break;
			}
			else if(e.type == SDL_KEYDOWN)
			{
				if(e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
					break;
				}else if(e.key.keysym.sym == SDLK_a)
				{
					SDL_BlitSurface(getimage , NULL , screen, NULL);

					SDL_UpdateWindowSurface(window);
				}else if(e.key.keysym.sym ==SDLK_s)
				{
					SDL_BlitSurface(getimage2 , NULL , screen, NULL);

					SDL_UpdateWindowSurface(window);
				}
			}
			
		}

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xffffff, 0x000000, 0x000000));

		//SDL_BlitSurface(getimage , NULL , screen, NULL);

		//SDL_UpdateWindowSurface(window);

	}
		SDL_FreeSurface(screen);
		screen = NULL;

		SDL_FreeSurface(getimage);
		getimage = NULL;
		
		SDL_DestroyWindow(window);

		window = NULL;
		

	return 0;
}