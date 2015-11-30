EXE=counted_ptr
OBJ=counted_ptr.o 
INCLUDE=-I./
LIB=
CXXFLAG=-g -std=c++11

all:$(EXE)

counted_ptr:$(OBJ)
	g++ $(LIB) $(LIB_PATH) $(OBJ) -o counted_ptr
counted_ptr.o:counted_ptr.h counted_ptr.cpp
	g++ $(INCLUDE) $(CXXFLAG) -c counted_ptr.cpp

clean:
	rm -rf $(EXE) *.o
