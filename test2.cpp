#include 	<SDL.h>
#include	<iostream>
#include 	<string>

#define NOSET SDL_WINDOWPOS_UNDEFINED

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;

class WindowSDL
{
public:
	WindowSDL(string title, int pX, int pY, int wW, int wH);

	bool CreateWindow();
	bool loadMedia();

	void (*Start)();
	void (*Update)();

	void Run();
private:
	string _title;
	int _pX, _pY, _wW, _wH;

	bool quit;
	SDL_Window* window;
	SDL_Surface* screen;

	void Close();
};

WindowSDL::WindowSDL(string title, int pX, int pY, int wW, int wH)
{
	_title = title;
	_pX = pX;
	_pY = pY;
	_wW = wW;
	_wH = wH;

	Start = NULL;
	Update = NULL;
}

bool WindowSDL::CreateWindow()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow(_title.c_str(), _pX, _pY, _wW, _wH, SDL_WINDOW_SHOWN);
	screen = SDL_GetWindowSurface(window);
}

void WindowSDL::Close()
{
	SDL_FreeSurface(screen);
	screen = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}

void WindowSDL::Run()
{
	if(Start != NULL)
	{
		Start();
	}

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
		}

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0x000000, 0x000000, 0x000000));

		if(Update != NULL)
		{
			Update();
		}

		SDL_UpdateWindowSurface(window);
	}
}

int main(int argc, char* argv[])
{
	WindowSDL test("Test", NOSET, NOSET, screenWidth, screenHeight);
	test.CreateWindow();
	test.Run();

	return 0;
}