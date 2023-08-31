DrawPoint: main.o Draw.o
	g++ main.o Draw.o -o DrawPoint
main.o: main.cpp
	g++ -c main.cpp -o main.o
Draw.o: Draw.cpp
	g++ -c Draw.cpp -o Draw.o
