NAME = push_swap

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
		gcc *.c -o $@ -L. -lft -I.

		 ./push_swap 5 4 8 1 6 7 3 2


clean:
	rm -rf push_swap

fclean: clean

re: clean all