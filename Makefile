all: compile link

compile:
	g++ -c main.cpp Game.cpp Player.cpp Map.cpp Enemy.cpp -I"C:\SFML-2.6.1\include" -DSFML_STATIC

link:
	g++ main.o Game.o Player.o Map.o Enemy.o -o PacMan -L"C:\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	rm -f main.o PacMan.exe Game.o Player.o Map.o Enemy.o
