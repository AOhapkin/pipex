NAME = pipex

# dirs
DIR_S = srcs/

INCLUDES = ./includes

# files
C_FILES = 	pipex.c\
            ft_split.c\
            utils.c

HEADER = $(INCLUDES)/pipex.h

SRCS = $(addprefix $(DIR_S), $(C_FILES))

OBJS = $(addprefix $(DIR_O), $(C_FILES:.c=.o))

CC = gcc
FLAGS = -Wall -Werror -Wextra

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: 		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
