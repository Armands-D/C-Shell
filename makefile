FILES = main.c
FLAGS = -Wall -Werror -fstack-protector -fsanitize=leak -fsanatize=address
OUT = main
CC = gcc

all: clean compile run clean

compile: $(FILES)
	$(CC) $(FILES) -o $(OUT)

run: $(OUT)
	-./$(OUT)

clean: $(OUT)
	rm $(OUT)

.PHONY: clean

