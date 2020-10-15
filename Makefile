all: Client Server

Client: Client.o ModularArithmetic.o
	g++	-o Client Client.o ModularArithmetic.o

Server: Server.o ModularArithmetic.o
	g++ -o Server Server.o ModularArithmetic.o

Client.o: Client.cpp ModularArithmetic.cpp
	g++ -c Client.cpp ModularArithmetic.cpp

Server.o: Server.cpp ModularArithmetic.cpp
	g++ -c Server.cpp ModularArithmetic.cpp

ModularArithmetic.o: ModularArithmetic.cpp ModularArithmetic.h
	g++ -c ModularArithmetic.cpp

clean:
	-rm Client Server *.o

.PHONY: all clean