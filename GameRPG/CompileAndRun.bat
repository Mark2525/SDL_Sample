@ECHO OFF

CLS

SET Include=-IC:\SDL\SDL2-2.0.3\include -IC:\SDL\SDL2-2.0.3\i686-w64-mingw32\include\SDL2 -IC:\SDL\SDL2-2.0.3\x86_64-w64-mingw32\include\SDL2 -IC:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\include\SDL2 -IC:\SDL\SDL2_image-2.0.0\x86_64-w64-mingw32\include\SDL2
SET Library=-LC:\SDL\SDL2-2.0.3\lib -LC:\SDL\SDL2-2.0.3\i686-w64-mingw32\lib -LC:\SDL\SDL2-2.0.3\x86_64-w64-mingw32\lib -LC:\SDL\SDL2_image-2.0.0\i686-w64-mingw32\lib -LC:\SDL\SDL2_image-2.0.0\x86_64-w64-mingw32\lib
SET Flag_Compile=-w -Wl,-subsystem,windows
SET Flag_Library=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image

SET Source=Game.cpp GameWindow.cpp GameTexture.cpp GameObject.cpp

SET Debug=n
SET /P Debug=You can show Debug (y):

IF %Debug% == y (

	SET Flag_Compile=-w
	)

IF NOT EXIST "bin\" (
	MKDIR bin
)

g++ %Source% %Include% %Library% %Flag_Compile% %Flag_Library% -o bin/RunGame

START /WAIT bin/RunGame
RMDIR /S /Q bin