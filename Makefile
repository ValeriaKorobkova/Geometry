build: main.cpp
	g++ -Wall main.cpp -o geometry

format: *.c
	clang-format -i *.cpp
