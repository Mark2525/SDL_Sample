#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


const int screenWidth = 800;
const int screenHeight = 600;

SDL_Window* window;
SDL_Renderer* render;
SDL_Texture* text;
SDL_Texture* text2;


SDL_Texture* loadMedia(const char* path)
{
	SDL_Surface* img = IMG_Load(path);

	SDL_Texture* tex = SDL_CreateTextureFromSurface(render, img);

	SDL_FreeSurface(img);
	img = NULL;

	return tex;
}

int main(int argc, char* argv[])
{
	std::cout << argc << " : " << argv[1] << std::endl;

	bool quit = false;

	SDL_Init(SDL_INIT_EVERYTHING);

	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	render = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	text = loadMedia("imagePNG.png");
	text2 = loadMedia("imageJPG.jpg");
	
	SDL_Texture* t;
	t = text;

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
					t = text;		
				}else if(e.key.keysym.sym == SDLK_s)
				{
					t = text2;
				}else if(e.key.keysym.sym == SDLK_d)
				{
					t = NULL;
				}
			}
			
		}

		SDL_SetRenderDrawColor( render, 0x50, 0x50, 0x50, 0xFF );

		SDL_RenderClear( render );

		SDL_RenderCopy( render, t, NULL, NULL );

		SDL_RenderPresent( render );

	}

	SDL_DestroyTexture(text);
	SDL_DestroyTexture(text2);
		

	return 0;
}