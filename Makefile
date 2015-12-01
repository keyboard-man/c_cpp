EXE=counted_ptr
OBJ=counted_ptr_test.o
INCLUDE=-I./
LIB=
CXXFLAG=-g -std=c++11

all:$(EXE)

counted_ptr:$(OBJ)
	g++ $(LIB) $(LIB_PATH) $(OBJ) -o counted_ptr
counted_ptr_test.o:counted_ptr_test.cpp
	g++ $(INCLDUE) $(CXXFLAG) -c counted_ptr_test.cpp

clean:
	rm -rf $(EXE) *.o
