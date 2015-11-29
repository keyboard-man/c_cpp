LIBS=-lACE -lboost_thread -lboost_system
INCLUDE=-I./
CXXFLAGS=-std=c++11 -g
EXE=ReactorServer McastRecver McastSender Task

all:$(EXE)

ReactorServer:ReactorServer.o ServiceHandler.o
	g++ ReactorServer.o ServiceHandler.o -o ReactorServer $(LIBS)
ReactorServer.o:ReactorServer.cpp
	g++ -c ReactorServer.cpp $(INCLUDE) $(CXXFLAGS)
ServiceHandler.o:ServiceHandler.cpp ServiceHandler.h
	g++ -c ServiceHandler.cpp $(INCLUDE) $(CXXFLAGS)

McastRecver:mcast_recver.cpp
	g++ mcast_recver.cpp -o McastRecver $(INCLUDE) $(CXXFLAGS) $(LIBS)

McastSender::mcast_sender.cpp
	g++ mcast_sender.cpp -o McastSender $(INCLUDE) $(CXXFLAGS) $(LIBS)

Task:task.cpp
	g++ task.cpp -o Tast $(INCLUDE) $(CXXFLAGS) $(LIBS)


clean:
	rm -rf $(EXE) *.o
