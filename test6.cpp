#include	<SDL.h>
#include	<SDL_image.h>

const	int sW = 900;
const	int sH = 700;

SDL_Window* window;
SDL_Renderer* render;

int main(int argc, char* argv[])
{	
	bool quit = false;
	SDL_Init(SDL_INIT_EVERYTHING);
	
	window = SDL_CreateWindow("Test Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sW, sH, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );

	int _X = 0 ,_Y = 0;
	
	bool kU = false;
	bool kD = false;
	bool kL = false;
	bool kR = false;

	SDL_Event e;

	while(!quit)
	{
		while(SDL_PollEvent(&e) != 0)
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
				break;
			}else if(e.type == SDL_KEYDOWN)
			{
				
				if(e.key.keysym.sym == SDLK_ESCAPE)
				{
					quit = true;
					break;
				}else if(e.key.keysym.sym == SDLK_d)
				{
					//_X += 50;
					kR = true;
				}else if(e.key.keysym.sym == SDLK_s)
				{
					//_Y += 50;
					kD = true;
				}else if(e.key.keysym.sym == SDLK_a)
				{
					//_X -= 50;
					kL = true;
				}else if(e.key.keysym.sym == SDLK_w)
				{
					//_Y -= 50;
					kU = true;
				}
			}
			else if(e.type == SDL_KEYUP)
			{
				if(e.key.keysym.sym == SDLK_w)
				{
					//_Y -= 50;
					kU = false;
				}
				else if(e.key.keysym.sym == SDLK_s)
				{
					//_Y += 50;
					kD = false;
				}
				if(e.key.keysym.sym == SDLK_a)
				{
					//_X -= 50;
					kL = false;
				}
				else if(e.key.keysym.sym == SDLK_d)
				{
					//_X += 50;
					kR = false;
				}
			}
		}

		if(kU)
		{
			_Y -= 5;
		}
		if(kD)
		{
			_Y += 5;
		}
		if(kL)
		{
			_X -= 5;
		}
		if(kR)
		{
			_X += 5;
		}

		if(_X <= 0)
		{
			_X = 0;
		}
		else if(_X >= sW-50)
		{
			_X = sW-50;
		}
		if (_Y <= 0)
		{
			_Y = 0;
		}else if(_Y >= sH-50)
		{
			_Y = sH-50;
		}

		SDL_Rect fr = {_X, _Y, 50, 50};

		SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xFF);

		SDL_RenderClear(render);

		SDL_SetRenderDrawColor(render, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderFillRect(render , &fr);

		SDL_Rect outlineRect = {sW / 6, sH / 6, sW *2 /3, sH *2 /3};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0XFF);
		SDL_RenderDrawRect( render, &outlineRect );

		
		SDL_RenderPresent(render);
	}

	return 0;
}