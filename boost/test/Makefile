CC=gcc
XX=g++
CFLAGS=-Wall -D_REENTRANT -std=c++11
CXXFLAGS=$(CFLAGS)
INCLUDE=-I./
LIBS=-lpthread -lrt
OBJS=$(patsubst %.c,%.o,$(wildcard *.c)) $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TEST=$(patsubst %.c,%,$(wildcard *.c)) $(patsubst %.cpp,%,$(wildcard *.cpp)) 
BUILD=

.PHONY:clean echo debug
	
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
%.o: %.cpp
	$(XX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

ifeq ($(BUILD),debug)
    CFLAGS += -g -O0
else
    CFLAGS += -O2 -s -DNDEBUG
endif

all:$(TEST)

$(TEST):$(OBJS)
	$(XX) $(subst ,,$@).o -o $@ $(LIBS)

clean:
	rm -f *.o $(TEST)

echo:
	echo $(TEST)
	echo $(OBJS)

debug:
	make "BUILD=debug"
