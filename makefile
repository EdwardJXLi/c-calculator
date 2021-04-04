CC = gcc
CFLAGS = -I -g -Wall
TARGET = run
FILES = main.o utils/linkedlist.o utils/parse.o

default: compile

compile: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)
