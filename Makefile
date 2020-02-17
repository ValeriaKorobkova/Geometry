build: main.c
	g++ -Wall main.c -o geometry

format: *.c
	clang-format -i *.c
