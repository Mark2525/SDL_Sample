#include	<SDL.h>
#include	<SDL_image.h>
#include	<iostream>

const int sw = 800;
const int sh = 600;

SDL_Texture* text;


class MarkEngine
{
public:
	SDL_Event e;

	MarkEngine();
	void Init(const char* title, int screenWidth, int screenHeight);
	SDL_Texture* LoadeTexture(const char* path);

	bool IsPlay();
	SDL_Renderer* GetRenderer();

	void End();
private:
	bool quit;

	SDL_Window* window;
	SDL_Renderer* render;
};

MarkEngine::MarkEngine()
{
	quit = false;
	window = NULL;
	render = NULL;
}

void MarkEngine::Init(const char* title, int screenWidth, int screenHeight)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	render = SDL_CreateRenderer(window, -1 ,SDL_RENDERER_ACCELERATED);
	
	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
}

SDL_Texture* MarkEngine::LoadeTexture(const char* path)
{
	SDL_Surface* img = IMG_Load(path);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(render, img);
	SDL_FreeSurface(img);
	img = NULL;

	return tex;
}


bool MarkEngine::IsPlay()
{
	return quit;
}

SDL_Renderer* MarkEngine::GetRenderer()
{
	return render;
}

void MarkEngine::End()
{
	quit = true;
}

int main(int argc, char* argv[])
{
	MarkEngine m;
	m.Init("TEST7", sw, sh);

	text = m.LoadeTexture("imageJPG.jpg");

	SDL_Texture* t;

	while(!m.IsPlay())
	{
		while(SDL_PollEvent(&m.e) != 0)
		{
			if(m.e.type == SDL_QUIT)
			{
				m.End();
				break;
			}else if(m.e.type == SDL_KEYDOWN)
			{
				if(m.e.key.keysym.sym == SDLK_ESCAPE)
				{
					m.End();
					break;
				}else if(m.e.key.keysym.sym == SDLK_a)
				{
					t = text;
				}else if(m.e.key.keysym.sym == SDLK_s)
				{
					t = NULL;
				}
			}
		}
		SDL_SetRenderDrawColor(m.GetRenderer(), 0x50, 0x50, 0x50, 0xff);

		SDL_RenderClear(m.GetRenderer());

		SDL_RenderCopy(m.GetRenderer(), t, NULL, NULL);

		SDL_RenderPresent(m.GetRenderer());
	}
	SDL_DestroyTexture(text);
	

	return 0;
}