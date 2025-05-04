INCL = ./include
SRC = ./src/*.c
FLAGS = -Wall -Wextra -fsanitize=address,null -O0 -g
CC = gcc

all: cpp parser hash

cpp:
	 $(CC) $(SRC) ./test/test_parser.cpp $(FLAGS) -I $(INCL) -o parser.out
	 ./parser.out
	 rm ./parser.out

parser:
	 $(CC) $(SRC) ./test/test_parser.c $(FLAGS) -I $(INCL) -o parser.out
	 ./parser.out
	 rm ./parser.out

hash:
	 $(CC) $(SRC) ./test/test_hash.c $(FLAGS) -I $(INCL) -o hash.out
	 ./hash.out
	 rm ./hash.out

