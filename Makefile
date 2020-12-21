NAME =		beepboopbeep.a

SRCS =		*.c

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
