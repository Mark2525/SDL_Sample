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

	window = SDL_CreateWindow("Text Rectangle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sW, sH, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	int _X= 0,_Y = 0;

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
					
					kR = true;
				}else if(e.key.keysym.sym == SDLK_s)
				{
					
					kD = true;
				}else if(e.key.keysym.sym == SDLK_a)
				{
					
					kL = true;
				}else if(e.key.keysym.sym == SDLK_w)
				{
					
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
			_Y -= 1;
		}
		if(kD)
		{
			_Y += 1;
		}
		if(kL)
		{
			_X -= 1;
		}
		if(kR)
		{
			_X += 1;
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

		SDL_SetRenderDrawColor(render, 0x00, 0x00, 0x00, 0xff);

		SDL_RenderClear(render);

		SDL_SetRenderDrawColor(render, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderFillRect(render , &fr);

		SDL_Rect outlineRect = {sW / 1024, sH / 1024, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect );

		SDL_Rect outlineRect2 = {sW / 5, sH / 1024, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect2 );

		SDL_Rect outlineRect3 = {sW *2/ 5, sH / 1024, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect3 );

		SDL_Rect outlineRect4 = {sW *3/ 5, sH / 1024, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect4 );

		SDL_Rect outlineRect5 = {sW *4/ 5, sH / 1024, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect5 );

		SDL_Rect outlineRect6 = {sW / 1024, sH / 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect6 );

		SDL_Rect outlineRect7 = {sW *1/5, sH / 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect7 );

		SDL_Rect outlineRect8 = {sW *2/5, sH / 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect8 );

		SDL_Rect outlineRect9 = {sW *3/5, sH / 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect9 );

		SDL_Rect outlineRect10 = {sW *4/5, sH / 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect10 );

		SDL_Rect outlineRect11 = {sW / 1024, sH *2/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect11 );

		SDL_Rect outlineRect12 = {sW *1/5, sH *2/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect12 );

		SDL_Rect outlineRect13 = {sW *2/5, sH *2/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect13 );
		SDL_RenderFillRect(render , &outlineRect13);

		SDL_Rect outlineRect14 = {sW *3/5, sH *2/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect14 );

		SDL_Rect outlineRect15 = {sW *4/5, sH *2/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect15 );

		SDL_Rect outlineRect16 = {sW /1024, sH *3/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect16 );
		
		SDL_Rect outlineRect16 = {sW *1 / , sH *3/ 5, sW  /5, sH /5};
		SDL_SetRenderDrawColor(render, 0X00, 0XFF, 0X00, 0Xff);
		SDL_RenderDrawRect( render, &outlineRect16 );




		
		SDL_RenderPresent(render);
	}

	return 0;
}