all: lie

lie: main.o parse.o buffer.o
	g++ main.o parse.o buffer.o -o lie

main.o: main.cpp
	g++ -c main.cpp

parse.o: parse.cpp
	g++ -c parse.cpp

buffer.o: buffer.cpp
	g++ -c buffer.cpp

clean:
	rm -f *.o lie
