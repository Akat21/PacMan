all: compile link

compile:
	g++ -c src/main.cpp src/Engine/Game.cpp src/GameObjects/Player.cpp src/GameObjects/Map.cpp src/GameObjects/Enemy.cpp src/GameObjects/Coins.cpp src/Menu/Menu.cpp -I"C:\SFML-2.6.1\include" -DSFML_STATIC

link:
	g++ main.o Game.o Player.o Map.o Enemy.o Coins.o Menu.o -o PacMan -L"C:\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	rm -f main.o PacMan.exe Game.o Player.o Map.o Enemy.o Coins.o Menu.o
