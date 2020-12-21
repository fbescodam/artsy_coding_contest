# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/21 17:22:55 by fbes          #+#    #+#                  #
#    Updated: 2020/12/21 18:24:58 by joellegallu   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		beepboopbeep.a

SRCS =		*.c

CFLAGS =

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)
	make fclean

.PHONY: all clean fclean re