#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


const int screenWidth = 600;
const int screenHeight = 400;

SDL_Window* window;
SDL_Surface* screen;
SDL_Surface* image;


void loadMedia()
{
	image = IMG_Load("imagePNG.png");
}

int main(int argc, char* argv[])
{
	std::cout << argc << " : " << argv[1] << std::endl;

	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);

	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	screen = SDL_GetWindowSurface(window);

	IMG_Init(IMG_INIT_PNG);

	loadMedia();
	

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
				}
			}
			
		}

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xffffff, 0x000000, 0x000000));

		SDL_BlitSurface(image , NULL , screen, NULL);

		SDL_UpdateWindowSurface(window);

	}
		SDL_FreeSurface(screen);
		screen = NULL;
		
		SDL_DestroyWindow(window);

		window = NULL;
		

	return 0;
}