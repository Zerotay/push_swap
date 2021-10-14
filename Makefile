NAME = push_swap

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
		make -C ./libft all bonus
		gcc *.c -o $@ -L./libft -lft -I./libft -I. -fsanitize=address

clean:
	make -C ./libft fclean

fclean: clean
		rm -f ./push_swap

re: fclean all