CPP := g++

FLAGS := -lws2_32 -std=c++0x -O2

server : main.cpp parser.o server.o
	$(CPP) parser.o server.o main.cpp $(FLAGS)  -o server

clean :
	rm server *.o

parser.o : httpParser.cpp 
	$(CPP) httpParser.cpp $(FLAGS) -c -o parser.o

server.o : httpServer.cpp
	$(CPP) httpServer.cpp $(FLAGS) -c -o server.o