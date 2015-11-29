LIBS=-lACE
INCLUDE=-I./
CXXFLAGS=-std=c++11 -g
EXE=ReactorServer

ReactorServer:ReactorServer.o ServiceHandler.o
	g++ ReactorServer.o ServiceHandler.o -o ReactorServer $(LIBS)
ReactorServer.o:ReactorServer.cpp
	g++ -c ReactorServer.cpp $(INCLUDE) $(CXXFLAGS)
ServiceHandler.o:ServiceHandler.cpp ServiceHandler.h
	g++ -c ServiceHandler.cpp $(INCLUDE) $(CXXFLAGS)

clean:
	rm -rf $(EXE) *.o
