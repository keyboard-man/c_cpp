CC=gcc
XX=g++
CFLAGS=-Wall -D_REENTRANT -g -std=c++11
INCLUDE=-I./
LIBS=-lpthread -lrt
OBJS=timer.o progress_timer.o new_progress_timer.o
TEST=timer progress_timer new_progress_timer

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
%.o: %.cpp
	$(XX) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:$(TEST)

$(TEST):$(OBJS)
	$(XX) $(LIBS) $(subst ,,$@).o -o $@

clean:
	rm -f *.o $(TEST)
