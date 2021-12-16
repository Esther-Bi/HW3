CC = gcc
AR = ar
ACTIONS = functions.o
FLAGS = -g -Wall
LM = -lm
HEADER = header.h
MAIN = main.o


all: stringProg

functions.o: functions.c $(HEADER)
	$(CC) $(FLAGS) -c functions.c

#creat main
stringProg: $(MAIN) functions.o
	$(CC) $(FLAGS) -o stringProg $(MAIN) functions.o $(LM)


main.o: main.c $(HEADER)
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm -f *.o *.a stringProg