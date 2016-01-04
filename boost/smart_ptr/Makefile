CC=gcc
XX=g++
CFLAGS=-Wall -D_REENTRANT -g -std=c++11
CXXFLAGS=$(CFLAGS)
INCLUDE=-I./
LIBS=-lpthread -lrt
OBJS=$(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TEST=$(patsubst %.c,%,$(wildcard *.c)) $(patsubst %.cpp,%,$(wildcard *.cpp)) 

.PHONY:clean echo

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
%.o: %.cpp
	$(XX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

all:$(TEST)

$(TEST):$(OBJS)
	$(XX) $(subst ,,$@).o -o $@ $(LIBS)

clean:
	rm -f *.o $(TEST)

echo:
	echo $(TEST)
	echo $(OBJS)
