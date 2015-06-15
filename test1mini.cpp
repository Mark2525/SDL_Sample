#include "WindowSDL.h"

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;


int main(int argc, char* argv[])
{
	
	WindowSDL test("Test Make Window", NOSET, NOSET, screenWidth, screenHeight );
	test.CreateWindow();
	test.Run();


	return 0;
}

/*
g++ (class *.cpp) (include -I) (library -L) -lmingw32 -lSDL2main -lSDL2 -o (.exe)
*/