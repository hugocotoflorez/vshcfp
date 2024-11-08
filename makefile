test:
	gcc *.c -Wall -Wextra -fsanitize=address,null -O0 -o test.out
