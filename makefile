CC = gcc
CFLAGS = -I -g -Wall
TARGET = run

default: compile

compile: main.o utils/clean.o
	$(CC) $(CFLAGS) main.o utils/clean.o -o $(TARGET)
