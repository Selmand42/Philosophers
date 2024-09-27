NAME	=	philo
SRC		=	main.c helper.c fill_data.c utils0.c
OBJS 	= 	$(SRC:.c=.o)
CC 		= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror
RM	 	= 	rm -rf

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
re: fclean all

.PHONY: all clean fclean re
