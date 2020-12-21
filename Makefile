NAME =		beepboopbeep.a

SRCS =		*.c

CFLAGS =

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -fsanitize=address -o $(NAME) $(SRCS)

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean $(NAME)
	./$(NAME)

.PHONY: all clean fclean re
