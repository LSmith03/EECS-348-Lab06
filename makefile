Matrix_Manipulation: main.o
	g++ -std=c++11 -g -Wall -o main.cpp
	
main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.o
	
clean:
	rm *.o Matrix_Manipulation