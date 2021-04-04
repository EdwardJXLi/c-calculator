CC = gcc
CFLAGS = -I -g -Wall
TARGET = run
FILES = main.o utils/clean.o utils/linkedlist.o

default: compile

compile: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET)
