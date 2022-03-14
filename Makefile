NAME = pipex

# dirs

INCLUDES = ./includes

# files
SRCS = 	source/pipex.c\
            source/str_utils.c\
            source/utils.c

HEADER = $(INCLUDES)/pipex.h

OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: 		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
