CC = gcc
CFLAGS = -I -g -Wall
FLAGS = -lm
TARGET = run
FILES = main.o utils/helpers.o utils/linkedlist.o utils/error.o utils/parse.o utils/convert.o

default: compile

compile: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET) $(FLAGS)
