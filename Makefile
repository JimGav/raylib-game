

all:
	g++ src/main.cpp src/shooter.cpp src/projectile.cpp -I include -L lib -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows -o main 
	./main.exe

run:
	g++ src/main.cpp src/shooter.cpp src/projectile.cpp -I include -L lib -lraylib -lopengl32 -lgdi32 -lwinmm -mwindows -o main 
	./main.exe

clean:
	del main.exe main.o projectile.o shooter.o