INCL = ./include
SRC = ./src/*.c
FLAGS = -Wall -Wextra -fsanitize=address,null -O0 -g
CC = gcc

hash:
	 $(CC) $(SRC) ./test/test_hash.c $(FLAGS) -I $(INCL) -o hash.out

