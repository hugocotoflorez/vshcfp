INCL = ./include
SRC = ./src/*.c
FLAGS = -Wall -Wextra -fsanitize=address,null -O0 -g
CC = gcc

parser:
	 $(CC) $(SRC) ./test/test_parser.c $(FLAGS) -I $(INCL) -o parser.out
	 ./parser.out

hash:
	 $(CC) $(SRC) ./test/test_hash.c $(FLAGS) -I $(INCL) -o hash.out
	 ./hash.out

