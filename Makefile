all: lie

lie: main.o parse.o buffer.o quit.o help.o print.o open.o exit.o goto.o change.o
	g++ main.o parse.o buffer.o quit.o help.o print.o open.o exit.o goto.o change.o -o lie

main.o: main.cpp
	g++ -c main.cpp

parse.o: parse.cpp
	g++ -c parse.cpp

buffer.o: buffer.cpp
	g++ -c buffer.cpp

exit.o: exit.cpp
	g++ -c exit.cpp

quit.o: commands/quit.cpp
	g++ -c commands/quit.cpp

help.o: commands/help.cpp
	g++ -c commands/help.cpp

print.o: commands/print.cpp
	g++ -c commands/print.cpp

open.o: commands/open.cpp
	g++ -c commands/open.cpp

goto.o: commands/goto.cpp
	g++ -c commands/goto.cpp

change.o: commands/change.cpp
	g++ -c commands/change.cpp

clean:
	rm -f *.o lie
